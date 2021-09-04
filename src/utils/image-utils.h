#include <opencv2/core.hpp>
#include <opencv2/imgproc.hpp>
#include <opencv2/imgcodecs.hpp>
#include <opencv2/highgui.hpp>
#include <iostream>

#define CINZA_LIMITE 128
#define BRANCO 255

using namespace cv;
using namespace std;

int remove_bordas_brancas(string imagem_entrada, string output_path, string nome_imagem);
Mat inverte_imagem(Mat imagem);
Rect identifica_retangulo(Mat imagem_inversa);

