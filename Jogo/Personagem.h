#pragma once
#include "Entidade.h"
namespace Entidades
{
    namespace Personagems
    {
        class Personagem :
            public Entidade
        {
        protected:
            int vida;
            bool morto;
        public:
            Personagem(int X = 0, int Y = 0);
            ~Personagem();
            void executar();
            void receberDano(int valor);
        };
    }
}
