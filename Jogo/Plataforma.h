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
        public:
            Plataforma(int X, int Y, int tamX, int tamY);
            ~Plataforma();
            void executar();
        };
    }
}

