#include "image-utils.h"

int remove_bordas_brancas(string imagem_path, string output_path, string nome_arquivo)
{
	Mat imagem;
	Mat inversa;
	Rect retangulo;

	imagem = imread(imagem_path, IMREAD_COLOR);

	if(imagem.empty())
	{
		cout << "Erro ao ler imagem: " << imagem_path << endl;
		return 1;
	}

	inversa = inverte_imagem(imagem);
	retangulo = identifica_retangulo(inversa);

	imwrite(output_path + nome_arquivo + ".png", Mat(imagem, retangulo));

	return 0;

}

Mat inverte_imagem(Mat imagem)
{
	Mat inversa;

	cvtColor(imagem, inversa, CV_BGR2GRAY);
	threshold(inversa, inversa, CINZA_LIMITE, BRANCO, THRESH_BINARY_INV);
	
	return inversa;
}

Rect identifica_retangulo(Mat imagem_inversa)
{
	Mat pontos_brancos;
	Rect retangulo;

	findNonZero(imagem_inversa, pontos_brancos);
	retangulo = boundingRect(pontos_brancos);

	return retangulo;
}