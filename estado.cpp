#include <iostream>
#include <cstdlib>
#include "estado.h"

using namespace std;

void Estado::Criar()
{
    this->banana = false;
    this->poscaixa[0] = 4;
    this->poscaixa[1] = 1;
    this->posmacaco[0] = 0;
    this->posmacaco[1] = 1;
    this->posbanana[0] = 2;
    this->posbanana[1] = 0;
    this->anterior = NULL;
}

bool Estado::AndarFrente()
{
    if(this->posmacaco[1] == 1 && this->posmacaco[0]<this->poscaixa[0]-1)
    {
        this->posmacaco[0] +=1;
        return true;
    }
    else
        return false;
}

bool Estado::AndarTraz()
{
    if(this->posmacaco[1] == 1 && this->posmacaco[0]>0)
    {
        this->posmacaco[0] -=1;
        return true;
    }
    else
        return false;
}

bool Estado::Subir()
{
    if(this->posmacaco[0] == this->poscaixa[0]-1)
    {
        this->posmacaco[0]++;
        this->posmacaco[1]--;
        return true;
    }
    else
        return false;
}

bool Estado::Descer()
{
    if(this->posmacaco[1] == this->poscaixa[1]-1)
    {
        this->posmacaco[0]--;
        this->posmacaco[1]++;
        return true;
    }
    else
        return false;
}

bool Estado::Empurrar()
{
    if(this->posmacaco[0] == (this->poscaixa[0]-1) && poscaixa[0]<4)
    {
        this->posmacaco[0]++;
        this->poscaixa[0]++;
        return true;
    }
    else
        return false;
}

bool Estado::Puxar()
{
    if(this->posmacaco[0] == (this->poscaixa[0]-1) && posmacaco[0]>0)
    {
        this->posmacaco[0]--;
        this->poscaixa[0]--;
        return true;
    }
    else
        return false;
}

bool Estado::Pegar()
{
    if(this->posmacaco[1] == this->posbanana[1] && this->posmacaco[0] == this->posbanana[0])
    {
        this->banana = true;
        return true;
    }
    else
        return false;
}

bool Estado::Ganhou()
{
    if(banana == true && posmacaco[0] == 4 && posmacaco[1] == 0)
        return true;
    else
        return false;
}

void Estado::Escrever()
{
    cout << "   0 1 2 3 4 "<< endl;
    cout << "-------------" << endl;
    for(int i=0; i<2; i++)
    {
        cout << i << "| ";
        for(int j=0; j<5; j++)
        {
            if(banana == false && i== posbanana[1] && j == posbanana[0] && !(posmacaco[0]==posbanana[0] && posmacaco[1]==posbanana[1]))
                cout << "B ";
            else if(j == posmacaco[0] && i == posmacaco[1])
                cout << "M ";
            else if(j == poscaixa[0] && i == poscaixa[1])
                cout << "C ";
            else
                cout << "  ";
        }
        cout << "|"<<endl;
    }
    cout << endl << endl << endl;

}

bool Estado::Comparar(Estado atual)
{
    if(this->banana == atual.banana && this->posmacaco[0] == atual.posmacaco[0] && this->posmacaco[1] == atual.posmacaco[1] && this->poscaixa[0] == atual.poscaixa[0] && this->poscaixa[1] == atual.poscaixa[1])
        return true;
    else
        return false;
}
