#pragma once
#include "Obstaculo.h"
namespace Entidades
{
    namespace Obstaculos
    {
        class Caixa :
            public Obstaculo
        {
        private:
            bool Tem_Item;
            bool Quebrada;
        public:
            Caixa(int X, int Y);
            ~Caixa();
            void executar();
            void quebrar();
            const bool getItem();
            const bool getQuebrada();
            void Bloquear(Entidade* enti, Direcao dire);
        };
    }
}

