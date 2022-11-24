#pragma once
#include "Fase.h"
namespace Fases
{
    class Fase2 :
        public Fase
    {
    public:
        Fase2(bool dois_Joga);
        ~Fase2();
        void GerarSoldados();
    };
}

