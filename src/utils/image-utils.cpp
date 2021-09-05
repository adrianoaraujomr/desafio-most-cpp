#include "image-utils.h"

int remove_bordas_brancas(string imagem_path, string output_path, string nome_arquivo)
{
	Mat imagem, imagem_binaria, erosao_dilatacao;
	Rect retangulo;

	imagem = imread(imagem_path, IMREAD_COLOR);

	if(imagem.empty())
	{
		cout << "Erro ao ler imagem: " << imagem_path << endl;
		return 1;
	}

	imagem_binaria = gera_imagem_binaria(imagem);
	erosao_dilatacao = remocao_ruidos(imagem_binaria);
	retangulo = identifica_retangulo(erosao_dilatacao);

	imwrite(output_path + nome_arquivo + ".png", Mat(imagem, retangulo));

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

	matriz_erosao_dilatacoa = getStructuringElement(MORPH_RECT, Size(2*tamanho+1, 2*tamanho+1), Point(tamanho,tamanho));
	erode(resultado_final, resultado_final, matriz_erosao_dilatacoa);
	dilate(resultado_final, resultado_final, matriz_erosao_dilatacoa);

	return resultado_final;
}


Rect identifica_retangulo(Mat imagem_inversa)
{
	Mat pontos_brancos;
	Rect retangulo;

	findNonZero(imagem_inversa, pontos_brancos);
	retangulo = boundingRect(pontos_brancos);

	return retangulo;
}
