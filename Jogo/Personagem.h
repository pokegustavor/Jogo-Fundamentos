#pragma once
#include "Entidade.h"
using namespace Entidades;
class Personagem :
    public Entidade
{
protected:
    int vida;
    bool morto;
public:
    Personagem(int X = 0, int Y = 0);
    ~Personagem();
    void executar();
};

