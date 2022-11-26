#include "Inimigo.h"

Entidades::Personagems::Inimigo::Inimigo(const int X,const int Y):Personagem(X,Y)
{
	Alvo = nullptr;
	chefao = false;
}

Entidades::Personagems::Inimigo::~Inimigo()
{
}

void Entidades::Personagems::Inimigo::SetAlvo(Jogador* joga)
{
	Alvo = joga;
}

const bool Entidades::Personagems::Inimigo::getChefao()
{
	return chefao;
}
