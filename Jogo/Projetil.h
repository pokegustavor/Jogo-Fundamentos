#pragma once
#include "Entidade.h"
namespace Entidades
{
    class Projetil :
        public Entidade
    {
    private:
        int direX;
        int direY;
        bool inativo;
        const int velocidade;
    public:
        Projetil(const int posX,const int posY, int DireX, int DireY);
        ~Projetil();
        void setPostion(const int X,const int Y);
        void setDirection(int X,int Y);
        void executar();
        void setInativo(const bool inatividade);
        bool getInativo();

    };
}

