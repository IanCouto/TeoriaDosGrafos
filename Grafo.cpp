#include <iostream>
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

    //Nenhum dos nos estao no Grafo
    if( !procurarNo(id) && !procurarNo(id_destino) ){
        inserirNo(id);
        inserirNo(id_destino);
    }
    //Apenas um no esta no grafo
    else if( procurarNo(id) && !procurarNo(id_destino) ){
        inserirNo(id_destino);
    }
    else if( !procurarNo(id) && procurarNo(id_destino) ){
        inserirNo(id);
    }

    No* noOrigem = getNo(id);
    No* noDestino = getNo(id_destino);

    noOrigem->inserirAresta(id_destino,peso);
    noDestino->inserirAresta(id,peso);

    noOrigem->aumentarGrauEntrada();
    noDestino->aumentarGrauEntrada();

}

void Grafo::mostrarGrafo() {
    for(No* no = primeiro_no; no != nullptr; no = no->getProximoNo()){
        cout << no->getId() << ".";
        for(Aresta* aresta = no->getPrimeiraAresta(); aresta != nullptr; aresta = aresta->getProximaAresta()){
            No* aux = getNo(aresta->getIdDestino());
            if(aresta == no->getPrimeiraAresta() )
                cout << aux->getId();
            else
                cout << "," << aux->getId();
        }
        cout << " - Grau de Entrada: " << no->getGrauEntrada();
        cout << " - Grau de Saida: " << no->getGrauSaida();
        cout << " - Peso: " << no->getPeso();
        cout << endl;
    }
}




