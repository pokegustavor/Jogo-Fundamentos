#pragma once
#include "Entidade.h"
#include <math.h>
using namespace Entidades;
class Projetil :
    public Entidade
{
private:
    int direX;
    int direY;
    bool inativo;
    const int velocidade;
public:
    Projetil(int posX, int posY, int DireX, int DireY);
    ~Projetil();
    void setPostion(int X, int Y);
    void setDirection(int X, int Y);
    void executar();
    void setInativo(bool inatividade);
    bool getInativo();
    
};

