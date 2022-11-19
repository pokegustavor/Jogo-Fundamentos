#pragma once
#include "Inimigo.h"
#include <stdlib.h>
#include <time.h>
namespace Entidades
{
    namespace Personagems
    {
        class Soldado :
            public Inimigo
        {
        private:
            int grau;
        public:
            Soldado(int X, int Y);
            ~Soldado();
            void executar();
            void Danar(Jogador* alvo);
        };
    }
}
