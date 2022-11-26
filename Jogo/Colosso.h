#pragma once
#include "Inimigo.h"
#include "Soldado.h"
#include <time.h>
namespace Entidades
{
    namespace Personagems
    {
        class Colosso :
            public Inimigo
        {
        private:
            bool rapido;
            clock_t ultimoSolda;
        public:
            Colosso(const int X,const int Y);
            ~Colosso();
            void executar();
            void Danar(Jogador* alvo);
        };
    }
}
