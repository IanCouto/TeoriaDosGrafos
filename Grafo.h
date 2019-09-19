#ifndef TEORIADOSGRAFOS_GRAFO_H
#define TEORIADOSGRAFOS_GRAFO_H

#include "No.h"

using namespace std;

class Grafo{
private:
    int ordem;
    int quant_aresta;
    bool direcionado;
    bool ponderado_aresta;
    bool ponderado_no;
    No* primeiro_no;
    No* ultimo_no;

    int mapeamento(int* mapa, int id);
	void auxDijkstra(float* distancia, int* aPercorrer, int* noAnterior, int* mapa, int atual);

public:
    //Contrutor e Destrutor
    Grafo(int ordem, bool direcionado, bool ponderadoAresta, bool ponderadoNo);
    ~Grafo();

    //Getters
    int getOrdem();
    int getQuantAresta();
    bool getDirecionado();
    bool getPonderadoAresta();
    bool getPonderadoNo();
    No* getPrimeiroNo();
    No* getUltimoNo();
    No *getNo(int id);

    //Setters
    void setQuantAresta(int val);

    //Outros Metodos
    bool procurarNo(int id);
    void inserirNo(int id);
    void inserirAresta(int id, int id_destino, float peso);
    void mostrarGrafo(ofstream& arquivo_saida);
    void mostrarArestas(ofstream& arquivo_saida);
    void mostrarNos(ofstream& arquivo_saida);

    //FUNCIONALIDADES

    void caminhamentoLargura(int id_no, ofstream &arquivo_saida);
    void caminhamentoProfundidade(int id_no, ofstream &arquivo_saida);
    void fechoTransitivoDireto(No* no, ofstream &arquivo_saida);
    void fechoTransitivoIndireto(No no, ofstream &arquivo_saida);
    void dijkstra(No* noU, No* noV, ofstream& arquivo_saida);
    void floyd(No noU, No noV, ofstream &arquivo_saida);
    void AGMPrim(ofstream &arquivo_saida);
    void AGMKruskal(ofstream &arquivo_saida);
    void fechoTriadico(ofstream &arquivo_saida);
};
#endif //TEORIADOSGRAFOS_GRAFO_H
