#pragma once
#include "Obstaculo.h"
namespace Entidades
{
    namespace Obstaculos
    {
        class Plataforma :
            public Obstaculo
        {
        private:
            bool movel;
            bool subindo;
            int meio;
        public:
            Plataforma(const int X,const int Y,const int tamX,const int tamY,const bool Movel = false);
            ~Plataforma();
            void executar();
            const bool getMovel();
            const bool getSubindo();
            void Bloquear(Entidade* enti, Direcao dire);
        };
    }
}

