#include <iostream>
#include <cstdlib>
#include "pilha.h"

using namespace std;

void Pilha::Criar()
{
    this->topo = -1;
}

void Pilha::Empilhar(Estado elemento)
{
    if(!Cheia())
    {
        this->elementos[++topo] = elemento;
        //cout << "empilhar" << elemento <<  endl;
    }
    else
        cout << "A pilha esta cheia" << endl;
}

Estado Pilha::Desempilhar()
{
    if(!Vazia())
    {
        //cout << "desempilhar" << endl;
        return this->elementos[topo--];
    }
    else
        cout << "A pilha esta vazia" << endl;
}


bool Pilha::Cheia()
{
    return (topo == TAMANHO-1) ? true : false;
}

bool Pilha::Vazia()
{
    return (topo == -1) ? true : false;
}

void Pilha::Exibir()
{
    for(int i=topo; i>=0; i--)
    {
        this->elementos[i].Escrever();
        system("pause");
        system("cls");
    }
}




