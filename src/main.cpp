#include "utils/image-utils.h"


int main( int argc, char** argv)
{

	if( argc < 2) {
        cerr << "Uso: " << argv[0] << " Necessida de tres argumentos, o primeiro o caminho para a imagem de entrada, o segundo o caminho para salvar o resultado e por ultimo o nome do arquivo da imagem." << endl;
        return 1;
	}

	string image_path = argv[1];
	string output_path = argv[2];
	string nome_arquivo = argv[3];


	return remove_bordas_brancas(image_path, output_path, nome_arquivo);
}
