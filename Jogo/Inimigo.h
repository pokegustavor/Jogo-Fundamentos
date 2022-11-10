#pragma once
#include "Personagem.h"
#include "Jogador.h"
class Inimigo :
    public Personagem
{
protected:
    bool chefao;
public:
    Jogador* Alvo;
    Inimigo(int X,int Y);
    ~Inimigo();
    void SetAlvo(Jogador* joga);
};

