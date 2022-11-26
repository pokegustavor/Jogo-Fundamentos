#pragma once
#include "Fase.h"
namespace Fases
{
    class Fase2 :
        public Fase
    {
    protected:
        void GerarSoldados();
        void GerarPlataformas();
        void GerarColossos();
        void GerarCaixas();
    public:
        Fase2(bool joga_dois);
        ~Fase2();
        
    };
}

