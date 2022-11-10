#include "Inimigo.h"

Inimigo::Inimigo(int X, int Y):Personagem(X,Y)
{
	Alvo = nullptr;
	chefao = false;
}

Inimigo::~Inimigo()
{
}

void Inimigo::SetAlvo(Jogador* joga)
{
	Alvo = joga;
}
