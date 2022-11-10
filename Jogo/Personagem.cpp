#include "Personagem.h"

Personagem::Personagem(int X, int Y):Entidade(X,Y)
{
	vida = 1;
	morto = false;
	Visual.setFillColor(sf::Color::Cyan);
}

Personagem::~Personagem()
{
}

void Personagem::executar()
{
	if(vida <= 0)
	{
		morto = true;
	}
}
