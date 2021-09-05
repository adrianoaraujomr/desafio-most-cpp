#include <opencv2/core.hpp>
#include <opencv2/imgproc.hpp>
#include <opencv2/imgcodecs.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/photo.hpp>
#include <iostream>

#define FORCA_FILTRO 2
#define TAMANHO_EROSAO_DILATACAo 2
#define BRANCO 255

using namespace cv;
using namespace std;

int remove_bordas_brancas(string imagem_entrada, string output_path, string nome_imagem);
Mat gera_imagem_binaria(Mat imagem);
Mat remocao_ruidos(Mat imagem_binaria);
Mat identifica_retangulo(Mat imagem_inversa);
Mat identifica_retangulo_minimo(Mat imagem_base, Mat imagem_binaria);
