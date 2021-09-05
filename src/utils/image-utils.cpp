#include "image-utils.h"

int remove_bordas_brancas(string imagem_path, string output_path, string nome_arquivo)
{
	Mat imagem, imagem_binaria, erosao_dilatacao;
	Rect retangulo;

	imagem = imread(imagem_path, IMREAD_COLOR);

	if (imagem.empty())
	{
		cout << "Erro ao ler imagem: " << imagem_path << endl;
		return 1;
	}

	imagem_binaria = gera_imagem_binaria(imagem);
	erosao_dilatacao = remocao_ruidos(imagem_binaria);

	imwrite(output_path + nome_arquivo + ".png", identifica_retangulo(imagem, erosao_dilatacao));

	return 0;
}

Mat gera_imagem_binaria(Mat imagem)
{
	Mat imagem_binaria;

	cvtColor(imagem, imagem_binaria, CV_BGR2GRAY);
	threshold(imagem_binaria, imagem_binaria, 0, BRANCO, THRESH_BINARY_INV | THRESH_OTSU);

	return imagem_binaria;
}

Mat remocao_ruidos(Mat imagem_binaria)
{
	Mat resultado_final, matriz_erosao_dilatacoa;
	int tamanho = TAMANHO_EROSAO_DILATACAo;

	fastNlMeansDenoising(imagem_binaria, resultado_final, FORCA_FILTRO);

	matriz_erosao_dilatacoa = getStructuringElement(MORPH_RECT, Size(2 * tamanho + 1, 2 * tamanho + 1), Point(tamanho, tamanho));
	erode(resultado_final, resultado_final, matriz_erosao_dilatacoa);
	dilate(resultado_final, resultado_final, matriz_erosao_dilatacoa);

	return resultado_final;
}

Mat identifica_retangulo(Mat imagem_base, Mat imagem_binaria)
{
	Mat pontos_brancos;
	Rect retangulo;

	findNonZero(imagem_binaria, pontos_brancos);
	retangulo = boundingRect(pontos_brancos);

	return Mat(imagem_base, retangulo);
}

Mat identifica_retangulo_minimo(Mat imagem_base, Mat imagem_binaria)
{
	Point2f centro_imagem = Point2f(imagem_binaria.cols / 2, imagem_binaria.rows / 2);
	Size tamanho_final = Size(imagem_binaria.cols, imagem_binaria.rows);
	Mat pontos_brancos, matriz_transformacao, imagem_rotacionada;
	RotatedRect retangulo;

	findNonZero(imagem_binaria, pontos_brancos);
	retangulo = minAreaRect(pontos_brancos);

	matriz_transformacao = getRotationMatrix2D(centro_imagem, retangulo.angle, 1);
	warpAffine(imagem_binaria, imagem_rotacionada, matriz_transformacao, tamanho_final);
	warpAffine(imagem_base, imagem_base, matriz_transformacao, tamanho_final);

	return Mat(imagem_base, boundingRect(imagem_rotacionada));
}
