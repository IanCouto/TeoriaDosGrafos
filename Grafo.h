

#ifndef TEORIADOSGRAFOS_GRAFO_H
#define TEORIADOSGRAFOS_GRAFO_H

#include "No.h"

class Grafo{
private:
    int ordem;
    int quant_aresta;
    bool direcionado;
    bool ponderado_aresta;
    bool ponderado_no;
    No* primeiro_no;
    No* ultimo_no;

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



};
#endif //TEORIADOSGRAFOS_GRAFO_H
