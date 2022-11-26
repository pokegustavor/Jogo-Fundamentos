#pragma once
#include "Obstaculo.h"
namespace Entidades
{
    namespace Obstaculos
    {
        class Espinho :
            public Obstaculo
        {
        private:
            bool afiado;
        public:
            Espinho(const int X,const int Y);
            ~Espinho();
            void Danar(Jogador* alvo);
            void executar();
            void Bloquear(Entidade* enti, Direcao dire);
        };
    }
}

