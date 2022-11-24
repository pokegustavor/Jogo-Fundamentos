#include "Plataforma.h"

Entidades::Obstaculos::Plataforma::Plataforma(int X, int Y, int tamX, int tamY, bool Movel):Obstaculo(X,Y)
{
	Visual.setSize(sf::Vector2f(tamX, tamY));
	movel = Movel;
	subindo = true;
	meio = Y;
}

Entidades::Obstaculos::Plataforma::~Plataforma()
{
}

void Entidades::Obstaculos::Plataforma::executar()
{
	Visual.setFillColor(sf::Color::Green);
	if(movel)
	{
		if(subindo)
		{
			y--;
			if (meio - y > 80)subindo = false;
		}
		else
		{
			y++;
			if (y - meio > 80)subindo = true;
		}
	}
	imprimir();
}

const bool Entidades::Obstaculos::Plataforma::getMovel()
{
	return movel;
}

const bool Entidades::Obstaculos::Plataforma::getSubindo()
{
	return subindo;
}
