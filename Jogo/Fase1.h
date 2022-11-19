#pragma once
#include "Fase.h"
class Fase1 :
    public Fase
{
public:
    Fase1(bool joga_dois);
    ~Fase1();
    void GerarSoldados();
};

