#pragma once
#include "Inimigo.h"
class Soldado :
    public Inimigo
{
public:
    Soldado(int X, int Y);
    ~Soldado();
    void executar();
};

