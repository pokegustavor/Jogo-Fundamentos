#include "Personagem.h"

Entidades::Personagems::Personagem::Personagem(int X, int Y):Entidade(X,Y)
{
	vida = 1;
	morto = false;
	Visual.setFillColor(sf::Color::Cyan);
}

Entidades::Personagems::Personagem::~Personagem()
{
}

void Entidades::Personagems::Personagem::executar()
{
	x += deltaX;
	y += deltaY;
	if (x < 0)x = 0;
	if (y < 0)y = 0;
	if(vida <= 0)
	{
		morto = true;
	}
	imprimir();
}

void Entidades::Personagems::Personagem::receberDano(int valor)
{
	vida -= valor;
	if (vida <= 0)morto = true;
}
