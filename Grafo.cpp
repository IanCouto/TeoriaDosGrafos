#include "Grafo.h"
#include "No.h"

//Construtor
Grafo::Grafo(int ordem, bool direcionado, bool ponderado_aresta, bool ponderadoNo){
    this->ordem = ordem;
    this->direcionado = direcionado;
    this->ponderado_aresta = ponderado_aresta;
    this->ponderado_No = ponderado_No;
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

Node *Grafo::getPrimeiroNo()
{
    return this->primeiro_no;
}

Node *Grafo::getUltimoNo()
{
    return this->ultimo_no;
}
