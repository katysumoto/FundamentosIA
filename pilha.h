#ifndef PILHA_H_INCLUDED
#define PILHA_H_INCLUDED
#define TAMANHO 1000
#include "estado.h"



struct Pilha
{
    int topo;
    Estado elementos[TAMANHO];

    void Criar();
    void Empilhar(Estado elemento);
    Estado Desempilhar();
    void Exibir();
    bool Cheia();
    bool Vazia();

};

#endif // PILHA_H_INCLUDED
