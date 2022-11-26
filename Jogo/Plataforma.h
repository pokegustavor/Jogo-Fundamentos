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
            Plataforma(int X, int Y, int tamX, int tamY, bool Movel = false);
            ~Plataforma();
            void executar();
            const bool getMovel();
            const bool getSubindo();
            void Bloquear(Entidade* enti, Direcao dire);
        };
    }
}

