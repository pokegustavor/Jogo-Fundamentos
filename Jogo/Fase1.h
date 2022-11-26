#pragma once
#include "Fase.h"
namespace Fases
{
    class Fase1 :
        public Fase
    {
    protected:
        void GerarSoldados();
        void GerarPlataformas();
        void GerarAtiradores();
        void GerarEspinhos();
    public:
        Fase1(const bool joga_dois);
        ~Fase1();
    };
}

