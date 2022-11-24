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
            Espinho(int X, int Y);
            ~Espinho();
            void Danar(Jogador* alvo);
            void executar();
        };
    }
}

