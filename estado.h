#ifndef ESTADO_H_INCLUDED
#define ESTADO_H_INCLUDED

struct Estado
{
    Estado *anterior;
    int poscaixa[2];
    int posmacaco[2];
    int posbanana[2];
    bool banana;

    void Criar();
    bool AndarFrente();
    bool AndarTraz();
    bool Subir();
    bool Descer();
    bool Puxar();
    bool Empurrar();
    bool Pegar();
    bool Ganhou();
    void Escrever();
    bool Comparar(Estado atual);
};

#endif // PILHA_H_INCLUDED
