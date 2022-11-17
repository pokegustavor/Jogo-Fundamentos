#pragma once
#include "Inimigo.h"
#include "Projetil.h"
class Atirador :
    public Inimigo
{
private:
    Projetil* meu_Projetil;
public:
    Atirador();
    ~Atirador();
    void executar();
    Projetil* getProjetil();
};

