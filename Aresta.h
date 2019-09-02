//
// Created by rodrigo on 26/08/2019.
//

#ifndef TEORIADOSGRAFOS_ARESTA_H
#define TEORIADOSGRAFOS_ARESTA_H
class Aresta{
private:
    int id_destino;
    Aresta* proxima_aresta;
    float peso;

public:
    // Construtor e Destrutor
    Aresta(int id_destino);
    ~Aresta();
    // Getters
    int getIdDestino();
    Aresta* getProximaAresta();
    float getPeso();
    // Setters
    void setProximaAresta(Aresta* aresta);
    void setPeso(float peso);
};
#endif //TEORIADOSGRAFOS_ARESTA_H
