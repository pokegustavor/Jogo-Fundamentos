#pragma once
#include "Fase.h"
namespace Fases
{
    class Fase1 :
        public Fase
    {
    protected:
        void GerarSoldados();
        void GerarAtiradores();
        void GerarEspinhos();
    public:
        Fase1(bool joga_dois);
        ~Fase1();
    };
}

