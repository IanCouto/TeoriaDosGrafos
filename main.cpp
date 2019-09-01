#include <iostream>
#include <fstream>
#include <stdlib.h>
#include "Grafo.h"

using namespace std;

Grafo* leitura(ifstream& arquivo_entrada, int direcionado, int ponderadoArestas, int ponderadoNo){

    int ordem;
    int idNoOrigem;
    int idNoDestino;

    arquivo_entrada >> ordem;

    Grafo* grafo = new Grafo(ordem,direcionado,ponderadoAresta,ponderadoNo);

    //Leitura do arquivo



    return grafo;
}

int main(int argc, char* argv[]) {

    //Verificação se todos os parâmetros do programa foram entrados
    if (argc != 6) {

        cout << "ERRO: Esperado: ./<nome_programa> <arquivo_entrada> <arquivo_saida> <direcionado> <ponderado_arestas> <ponderado_no> " << endl;
        return 1;

    }

    //Abrindo arquivo de entrada
    ifstream arquivo_entrada;
    ofstream arquivo_saida;
    arquivo_entrada.open(argv[1], ios::in);
    arquivo_saida.open(argv[2], ios::out | ios::trunc);

    Grafo* grafo;

    if(arquivo_entrada.is_open())
        grafo = leitura(arquivo_entrada, atoi(argv[3]), atoi(argv[4]), atoi(argv[5])); //atoi = converte string para int
    else
        cout << "Nao foi possivel abrir o arquivo " << argv[1] << endl;


    //Fechando arquivo de entrada
    arquivo_entrada.close();

    //Fechando arquivo de saída
    arquivo_saida.close();

    return 0;
}