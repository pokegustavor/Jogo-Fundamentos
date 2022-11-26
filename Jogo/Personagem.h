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
            Personagem(const int X = 0,const int Y = 0);
            ~Personagem();
            void executar();
            void receberDano(const int valor);
            void setChao(const bool chao);
            const bool getMorto();
            const int getVidas();
        };
    }
}
