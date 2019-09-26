#include <iostream>
#include <fstream>
#include "Grafo.h"
#include "No.h"

using namespace std;

//Construtor
Grafo::Grafo(int ordem, bool direcionado, bool ponderado_aresta, bool ponderado_no){
    this->ordem = ordem;
    this->direcionado = direcionado;
    this->ponderado_aresta = ponderado_aresta;
    this->ponderado_no = ponderado_no;
    this->primeiro_no = this->ultimo_no = nullptr;
    this->quant_aresta = 0;
}

// Destrutor
Grafo::~Grafo()
{

    No *proximo_no = this->primeiro_no;

    while (proximo_no != nullptr)
    {
        proximo_no->removerTodasArestas();
        No *aux_no = proximo_no->getProximoNo();
        delete proximo_no;
        proximo_no = aux_no;
    }
}

//Getters

int Grafo::getOrdem()
{
    return this->ordem;
}
int Grafo::getQuantAresta()
{
    return this->quant_aresta;
}

bool Grafo::getDirecionado()
{
    return this->direcionado;
}

bool Grafo::getPonderadoAresta()
{
    return this->ponderado_aresta;
}

bool Grafo::getPonderadoNo()
{
    return this->ponderado_no;
}

No *Grafo::getPrimeiroNo()
{
    return this->primeiro_no;
}

No *Grafo::getUltimoNo()
{
    return this->ultimo_no;
}

//Setters

void Grafo::setQuantAresta(int val){
    this->quant_aresta++;
}

//Retorna um No com o determinado id, caso negativo retorna null
No *Grafo::getNo(int id){
    if(this->primeiro_no != nullptr){
        for(No* aux = primeiro_no; aux != nullptr; aux = aux->getProximoNo())
            if(aux->getId() == id)
                return aux;
    }

    return nullptr;
}

//Outros metodos

void Grafo::inserirNo(int id){
    //Verifica se existe pelo menos um No, caso negativo, o primeiro No sera setado
    if(this->primeiro_no != nullptr){
        No* no = new No(id);
        this->ultimo_no -> setProximoNo(no);
        this->ultimo_no = no;
    }
    else{
        this->primeiro_no = new No(id);
        this->ultimo_no = this->primeiro_no;
    }
}

//Verifica se o No esta no Grafo
bool Grafo::procurarNo(int id){

    if(this->primeiro_no != nullptr){
        for(No* aux = primeiro_no; aux != nullptr; aux = aux->getProximoNo())
            if(aux->getId() == id)
                return true;
    }

    return false;

}

void Grafo::inserirAresta(int id, int id_destino, float peso){

    //Se algum no nao estiver No nao estiver no grafo
    if( !procurarNo(id) )
        inserirNo(id);

    if( !procurarNo(id_destino) )
        inserirNo(id_destino);

    No* noOrigem = getNo(id);
    No* noDestino = getNo(id_destino);

    if(!getDirecionado()){
        noOrigem->inserirAresta(id_destino,peso);
        noDestino->inserirAresta(id,peso);

        noOrigem->aumentarGrauEntrada();
        noDestino->aumentarGrauEntrada();
    }
    else{
        noOrigem->inserirAresta(id_destino,peso);

        noOrigem->aumentarGrauSaida();
        noDestino->aumentarGrauEntrada();
    }

    this->quant_aresta++;

}


void Grafo::mostrarGrafo(ofstream& arquivo_saida) {
    arquivo_saida<<"-----------GRAFO------------"<<endl;
    for(No* no = primeiro_no; no != nullptr; no = no->getProximoNo()){
        arquivo_saida << no->getId() << ".";
        for(Aresta* aresta = no->getPrimeiraAresta(); aresta != nullptr; aresta = aresta->getProximaAresta()){
            No* aux = getNo(aresta->getIdDestino());
            if(aresta == no->getPrimeiraAresta() )
                arquivo_saida << aux->getId();
            else
                arquivo_saida << "," << aux->getId();
        }
        arquivo_saida<<endl;
    }
    arquivo_saida<<endl<<endl;
}

void Grafo::mostrarNos(ofstream& arquivo_saida) {
    arquivo_saida<<"-----------NOS------------"<<endl;
    arquivo_saida<<"No - Grau de Entrada - Grau de saida - Peso"<<endl;
    for(No* no = primeiro_no; no != nullptr; no = no->getProximoNo()){
        arquivo_saida << no->getId() << ".";
        arquivo_saida << " - E:" << no->getGrauEntrada();
        arquivo_saida << " - S:" << no->getGrauSaida();
        arquivo_saida << " - P:" << no->getPeso();
        arquivo_saida << endl;
    }
    arquivo_saida<<endl<<endl;
}

void Grafo::mostrarArestas(ofstream& arquivo_saida) {
    arquivo_saida<<"-----------ARESTAS------------"<<endl;
    arquivo_saida<<"[No de Origem , No de Destino] - Peso "<< endl;
    for(No* no = primeiro_no; no != nullptr; no = no->getProximoNo()){
        for(Aresta* aresta = no->getPrimeiraAresta(); aresta != nullptr; aresta = aresta->getProximaAresta()) {
            arquivo_saida << "[" << no->getId() << "," << aresta->getIdDestino() << "] - P: " << aresta->getPeso() << endl;
        }
    }
    arquivo_saida<<endl<<endl;
}

int Grafo::mapeamento(int* mapa, int id) {
    for(int i=0; i < this->getOrdem(); i++) {
        if(mapa[i] == id)
            return i;
    }
}

//------------FUNCIONALIDADES---------------

//CAMINHAMENTO EM LARGURA-------------------
//a função deve receber como parâmetro o Id de um nó e imprimir o conjunto de arestas visitadas a
//partir do mesmo em um percurso em largura indicando, para cada uma, se trata-se ou não de uma aresta
//de retorno
//Responsável:

void Grafo::caminhamentoLargura(int id_no, ofstream& arquivo_saida){

}

//-----------------------------------------

//CAMINHAMENTO EM PROFUNDIDADE-------------
//a função deve receber como parâmetro o Id de um nó e imprimir o conjunto de arestas visitadas a
//partir do mesmo em um percurso em profundidade indicando, para cada uma, se trata-se ou não de uma
//aresta de retorno
//Responsável:Wiliam

void Grafo::auxBuscaEmProfundidade(int id, bool* aux, ofstream& arquivo_saida){
    aux[id] = true;
    No* noAux= getNo(id);
    for(Aresta* arestaAux= noAux->getPrimeiraAresta();arestaAux!=nullptr;arestaAux=arestaAux->getProximaAresta()){
            if(aux[arestaAux->getIdDestino()]==false){
                arquivo_saida<<"["<<id<<" , "<<arestaAux->getIdDestino()<<"] nao é retorno"<<endl;
                auxBuscaEmProfundidade(arestaAux->getIdDestino(),aux,arquivo_saida);
            }
            else{
                arquivo_saida<<"["<<id<<","<<arestaAux->getIdDestino()<<"] é uma aresta de retorno"<<endl;
            }
    }
}

void Grafo::caminhamentoProfundidade(int id_no, ofstream& arquivo_saida){
    bool *aux=new bool[this->ordem];
    for (int i=0;i<this->ordem;i++){
        aux[i]=false;
    }
    auxBuscaEmProfundidade(id_no,aux,arquivo_saida);
}

//-----------------------------------------

//FECHO TRANSITIVO DIRETO DE UM DADO NÓ (PARA GRAFO ORIENTADO)
//para um dado nó v do grafo, a função deve imprimir o Id de todo nó u alcançável por um caminho
//direcionado com origem em v
//Responsável:

void Grafo::fechoTransitivoDireto(No* no, ofstream& arquivo_saida){
    if(this->getDirecionado()) {
        int* percorrido = new int[this->getOrdem()];
        int* mapa = new int[this->getOrdem()];
        int* acessivel = new int[this->getOrdem()];

        No* aux = this->getPrimeiroNo();
        for(int i=0; i < this->getOrdem(); i++, aux = aux->getProximoNo()) {
            mapa[i] = aux->getId();
            if(aux->getId() == no->getId())
                percorrido[i] = 1;
            else
                percorrido[i] = 0;
            acessivel[i] = 0;
        }

        aux = no;
        for(int flag=1; flag==1;){
            Aresta* aresta = aux->getPrimeiraAresta();
            percorrido[mapeamento(mapa, aux->getId())] = 1;
            int indiceDestino;
            while(aresta != nullptr) {
                indiceDestino = mapeamento(mapa, aresta->getIdDestino());
                if(!percorrido[indiceDestino]) {
                    acessivel[indiceDestino] = 1;
                }
                aresta = aresta->getProximaAresta();
            }
            flag=0;
            for(int i=0; i < this->getOrdem() && flag == 0; i++) {
                if(acessivel[i] && !percorrido[i]) {
                    aux = this->getNo(mapa[i]);
                    flag = 1;
                } else
                    flag = 0;
            }
        }

        arquivo_saida<<"---Fecho Transitivo Direto---"<<endl;
        arquivo_saida<<"[Conjunto de nos acessiveis com origem em v]"<<endl;
        arquivo_saida << "[";
        int priImpresao=1;
        for(int i=0; i < this->getOrdem(); i++) {
            if(acessivel[i] && priImpresao) {
                arquivo_saida << mapa[i];
                priImpresao = 0;
            } else if(acessivel[i])
                arquivo_saida << ", " << mapa[i];
        }
        arquivo_saida << "]" << endl;
        arquivo_saida << endl << endl;

        delete[] percorrido;
        delete[] mapa;
        delete[] acessivel;
    }
}

//-----------------------------------------

//FECHO TRANSITIVO INDIRETO DE UM DADO NÓ (PARA GRAFO ORIENTADO)
//para um dado nó v do grafo, a função deve imprimir o Id de todo nó u que pode alcançar o nó v por
//um caminho direcionado com origem em u
//Responsável:

void Grafo::fechoTransitivoIndireto(No* no, ofstream& arquivo_saida){
    if(this->getDirecionado()) {
        int* mapa = new int[this->getOrdem()];
        int* acessivel = new int[this->getOrdem()];

        No* aux = this->getPrimeiroNo();
        for(int i=0; i < this->getOrdem(); i++, aux = aux->getProximoNo()) {
            mapa[i] = aux->getId();
            if(aux->getId() == no->getId())
                acessivel[i] = 1;
            else
                acessivel[i] = 0;
        }
        //Continuar

        for(int flag=1; flag==1; ){
            flag = 0;
            aux = this->getPrimeiroNo();
            while(aux !=nullptr) {
                int indiceAtual = mapeamento(mapa, aux->getId());
                Aresta* aresta = aux->getPrimeiraAresta();
                while(aresta != nullptr) {
                    int indiceDestino = mapeamento(mapa, aresta->getIdDestino());
                    if(acessivel[indiceDestino] && !acessivel[indiceAtual]) {
                        acessivel[indiceAtual] = 1;
                        flag = 1;
                    }
                    aresta = aresta->getProximaAresta();
                }
                aux = aux->getProximoNo();
            }
        }

        arquivo_saida<<"---Fecho Transitivo Indireto---"<<endl;
        arquivo_saida<<"[Conjunto de nos que acessam v com origem em u]"<<endl;
        arquivo_saida << "[";
        int priImpresao=1;
        for(int i=0; i < this->getOrdem(); i++) {
            if(mapa[i] != no->getId()) {
                if(acessivel[i] && priImpresao) {
                    arquivo_saida << mapa[i];
                    priImpresao = 0;
                } else if(acessivel[i])
                    arquivo_saida << ", " << mapa[i];
            }
        }
        arquivo_saida << "]" << endl;
        arquivo_saida << endl << endl;

        delete[] mapa;
        delete[] acessivel;
    }
}

//-----------------------------------------

//DIJKSTRA: CAMINHO MÍNIMO (PARA GRAFOS ORIENTADOS OU NÃO ORIENTADOS)
//para um dado grafo (orientado ou não, ponderado ou não), a função deve receber o Id de dois
//vértices u e v e mostrar um caminho mínimo entre u e v, bem como o custo deste caminho calculado a
//partir do algoritmo de Dijkstra. O caminho a ser mostrado consiste na sequência de vértices entre u e v tal
//que o somatório dos pesos das arestas entre vértices consecutivos na sequência seja mínima. Note que,
//para grafos não ponderados, um caminho mínimo entre dois vértices consiste numa sequência de vértices
//entre os mesmos com o menor número de arestas
//Responsável:

void Grafo::dijkstra(No* noU, No* noV, ofstream& arquivo_saida){
    float* distancia = new float[this->getOrdem()];
    int* mapa = new int[this->getOrdem()];
    int* aPercorrer = new int[this->getOrdem()];
    int* noAnterior = new int[this->getOrdem()];

    No* no = this->getPrimeiroNo();
    for(int i=0; i < this->getOrdem(); i++, no = no->getProximoNo()) {
        mapa[i] = no->getId();
        if(no->getId() == noU->getId()) {
            distancia[i] = 0;
            aPercorrer[i] = 0;
        } else {
            distancia[i] = -1;
            aPercorrer[i] = 1;
        }
        noAnterior[i] = -1;
    }

    auxDijkstra(distancia, aPercorrer, noAnterior, mapa, noU->getId());

    arquivo_saida<<"---------DIJKSTRA---------"<<endl;
    arquivo_saida<<"[Caminho entre noU e noV] - custo de caminho minimo"<<endl;
    if(distancia[mapeamento(mapa, noV->getId())] != -1) {
        arquivo_saida << "[" << noV->getId();
        int caminho = noAnterior[mapeamento(mapa, noV->getId())];
        while(caminho != -1) {
            arquivo_saida << ", " << caminho;
            caminho = noAnterior[mapeamento(mapa, caminho)];
        }
        arquivo_saida << "] - " << distancia[mapeamento(mapa, noV->getId())] << endl;
        arquivo_saida << endl << endl;
    } else {
        arquivo_saida << "[" << noU->getId() << ", " << noV->getId() << "] - -1";
    }
    delete[] aPercorrer;
    delete[] noAnterior;
    delete[] distancia;
    delete[] mapa;
}
void Grafo::auxDijkstra(float* distancia, int* aPercorrer, int* noAnterior, int* mapa, int atual){
    No* no = this->getNo(atual);
    Aresta* aresta = no->getPrimeiraAresta();
    int indiceAtual = mapeamento(mapa, atual);
    int indiceAresta;
    while(aresta != nullptr) {
        indiceAresta = mapeamento(mapa, aresta->getIdDestino());
        if(distancia[indiceAresta] != -1) {
            if(this->getPonderadoAresta()) {
                if(distancia[indiceAresta] > distancia[indiceAtual] + aresta->getPeso()) {
                    distancia[indiceAresta] = distancia[indiceAtual] + aresta->getPeso();
                    noAnterior[indiceAresta] = atual;
                }
            } else {
                if(distancia[indiceAresta] > distancia[indiceAtual] + 1) {
                    distancia[indiceAresta] = distancia[indiceAtual] + 1;
                    noAnterior[indiceAresta] = atual;
                }
            }
        } else {
            if(this->getPonderadoAresta()) {
                distancia[indiceAresta] = distancia[indiceAtual] + aresta->getPeso();
                noAnterior[indiceAresta] = atual;
            } else {
                distancia[indiceAresta] = distancia[indiceAtual] + 1;
                noAnterior[indiceAresta] = atual;
            }
        }
        aresta = aresta->getProximaAresta();
    }
    int menor = -1;
    for(int i=0; i < this->getOrdem() && menor == -1; i++){
        if(aPercorrer[i]) {
            if(distancia[i] != -1) {
                menor = distancia[i];
                atual = mapa[i];
            }
        }
    }
    if(menor != -1) {
        for(int i=0; i < this->getOrdem(); i++) {
            if(aPercorrer[i])
                if(distancia[i] != -1)
                    if(distancia[i] < menor){
                        menor = distancia[i];
                        atual = mapa[i];
                    }
        }
        aPercorrer[indiceAtual] = 0;
        auxDijkstra(distancia, aPercorrer, noAnterior, mapa, atual);
    }
}

//-----------------------------------------

//FLOYD: CAMINHO MÍNIMO (PARA GRAFOS ORIENTADOS OU NÃO ORIENTADOS)
//para um dado grafo (orientado ou não, ponderado ou não), a função deve receber o Id de dois
//vértices u e v e mostrar um caminho mínimo entre u e v, bem como o custo deste caminho calculado a
//partir do algoritmo de Floyd. O caminho a ser mostrado consiste na sequência de vértices entre u e v tal
//que o somatório dos pesos das arestas entre vértices consecutivos na sequência seja mínima. Note que,
//para grafos não ponderados, um caminho mínimo entre dois vértices consiste numa sequência de vértices
//entre os mesmos com o menor número de arestas
//Responsável:

void Grafo::floyd(No noU,No noV, ofstream& arquivo_saida){

}

//-----------------------------------------

//ÁRVORE GERADORA MÍNIMA (PARA GRAFOS NÃO ORIENTADOS PONDERADOS OU NÃO) - PRIM
//para um dado grafo não orientado (ponderado ou não), utilizando o algoritmo de Prim, a função
//deve retornar um conjunto com n-1 arestas que conecte todos os nós do grafo e cujo somatório dos pesos
//das arestas seja mínimo. No caso de grafos não ponderados, qualquer conjunto com n-1 arestas que
//conecte o grafo é solução do problema
//Responsável:

void Grafo::AGMPrim(ofstream& arquivo_saida){

}

//-----------------------------------------

//ÁRVORE GERADORA MÍNIMA (PARA GRAFOS NÃO ORIENTADOS PONDERADOS OU NÃO) - KRUSKAL
//para um dado grafo não orientado (ponderado ou não), utilizando o algoritmo de Kruskal, a função
//deve retornar um conjunto com n-1 arestas que conecte todos os nós do grafo e cujo somatório dos pesos
//das arestas seja mínimo. No caso de grafos não ponderados, qualquer conjunto com n-1 arestas que
//conecte o grafo é solução do problema
//Responsável:

void Grafo::AGMKruskal(ofstream& arquivo_saida){

}

//-----------------------------------------

//FECHO TRIÁDICO---------------------------
//Um fecho triádico ocorre em uma rede social se duas pessoas que tem um amigo em comum
//também são amigas entre si. O coeficiente de agrupamento (clustering coefficient) de uma rede é uma
//métrica que indica a frequência com este fenômeno ocorre na rede.
//Dado um grafo G, chamamos de tríade um par de vértices {u,v} com um vizinho em comum w. Se
//os vértices u e v são vizinhos, dizemos que a tríade é fechada (este é um caso onde há um fecho triádico).
//Caso contrário, dizemos que a tríade é aberta. Note que para cada três vértices u, v e w mutuamente
//adjacentes, existem três tríades fechadas. O coeficiente de agrupamento de um grafo é dado pelo número
//de tríades fechadas divido pelo total de tríades (incluindo tríades abertas e fechadas). Convencionamos que
//o coeficiente de agrupamento de um grafo sem tríades é zero.
//Responsável:

void Grafo::fechoTriadico(ofstream& arquivo_saida){

}

//-----------------------------------------
