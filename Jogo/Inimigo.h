#pragma once
#include "Personagem.h"
#include "Jogador.h"
namespace Entidades
{
    namespace Personagems
    {
        class Inimigo :
            public Personagem
        {
        protected:
            bool chefao;
        public:
            Jogador* Alvo;
            Inimigo(int X, int Y);
            ~Inimigo();
            void SetAlvo(Jogador* joga);
            virtual void Danar(Jogador* alvo) = 0;
        };
    }
}

