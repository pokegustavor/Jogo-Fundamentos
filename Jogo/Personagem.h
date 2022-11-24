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
            bool noChao;
        public:
            Personagem(int X = 0, int Y = 0);
            ~Personagem();
            void executar();
            void receberDano(int valor);
            void setChao(bool chao);
            const bool getMorto();
            const int getVidas();
        };
    }
}
