#include <iostream>
#include "pilha.h"
#include "estado.h"
#include <cstdlib>
using namespace std;

int main()
{
    int aux;
    Estado *pont, state;
    Estado visitados[28];
    int atual = 0;
    Pilha IA, fim;

    //Inicialização de Pilhas e Estado inicial
    IA.Criar();
    fim.Criar();
    state.Criar();

    //Carregar Estado inicial na pilha
    IA.Empilhar(state);

    //Enquanto o objetivo não for concluido o jogo continuará
    while(!state.Ganhou())
    {
        state = IA.elementos[IA.topo];

        //Desempilha Estados já expandidos
        for(int i=0; i<atual; i++)
        {
            if(state.Comparar(visitados[i]))
            {
                IA.Desempilhar();
                state = IA.elementos[IA.topo];
            }
        }

        //Acresenta Estado q expandido a pilha de Estados expandidos
        visitados[atual] = state;
        atual ++;
        aux = IA.topo;
        if(!state.Ganhou())
        {
            //Jogadas possíveis
            if(state.AndarFrente())
            {
                IA.Empilhar(state);
                state.AndarTraz();
                //guarda estado anterior, afim de criar ao final um caminho para objetivo
                IA.elementos[IA.topo].anterior = &IA.elementos[aux];
            }
            if(state.AndarTraz())
            {
                IA.Empilhar(state);
                state.AndarFrente();
                IA.elementos[IA.topo].anterior = &IA.elementos[aux];
            }
            if(state.Descer())
            {
                IA.Empilhar(state);
                state.Subir();
                IA.elementos[IA.topo].anterior = &IA.elementos[aux];
            }
            if(state.Subir())
            {
                IA.Empilhar(state);
                state.Descer();
                IA.elementos[IA.topo].anterior = &IA.elementos[aux];
            }
            if(state.Empurrar())
            {
                IA.Empilhar(state);
                state.Puxar();
                IA.elementos[IA.topo].anterior = &IA.elementos[aux];
            }
            if(state.Puxar())
            {
                IA.Empilhar(state);
                state.Empurrar();
                IA.elementos[IA.topo].anterior = &IA.elementos[aux];
            }
            if(state.Pegar())
            {
                IA.Empilhar(state);
                state.banana = false;
                IA.elementos[IA.topo].anterior = &IA.elementos[aux];
            }
        }


    }

    //Empilhando Estados do caminho final
    pont = &IA.elementos[IA.topo];
    while(pont != NULL)
    {
        fim.Empilhar(*pont);
        pont = pont->anterior;

    }

    fim.Exibir();

    return 0;
}


