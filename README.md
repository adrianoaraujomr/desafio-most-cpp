# Desafio MOST

### Objetivo

Fazer uma aplicação que tentar remover ao máximo o espaço em branco ao redor de uma imagem.

### Rodar programa

Para gerar o binario do projeto basta executar o comando `make` no diretorio do projeto. Porém vale lembrar que para isto funcionar o opencv deve estar instalado, o comando `pkg-config --cflags --libs opencv` deve estar funcionando. Com o binário gerado basta executar o seguinte comando.

```
./bin/main [caminho para o arquivo] [diretorio de saida] [nome do arquivo de saida]
./bin/main /home/pessoa/Documentos/imagem.png /home/pessoa/Documentos/resultado/ resultado_final
```

### Processo

O processo para desenvolvimento da solução foi primeiramente buscar na internet como se poderia resolver o problema em questão. Foi descoberto que uma forma de resolver esse problema é fazer a binarição da imagem e usar das funções prontas do opencv para encontrar o retângulo que contem o conteúdo da imagem. O que foi em suma o que foi feito. O que foi adicionado a mais foi um passo para remoção de noise, consitindo em um algorimto para fazer essa redução e também os algoritmos de erosão seguido por dilatação que também podem remover ruídos.
