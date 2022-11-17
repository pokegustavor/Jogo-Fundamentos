#pragma once
#include "Inimigo.h"
#include "Projetil.h"
class Atirador :
    public Inimigo
{
private:
    Projetil* meu_Projetil;
public:
    Atirador(int X, int Y);
    ~Atirador();
    void executar();
    Projetil* getProjetil();
};

