#include "Plataforma.h"

Entidades::Obstaculos::Plataforma::Plataforma(int X, int Y, int tamX, int tamY):Obstaculo(X,Y)
{
	Visual.setSize(sf::Vector2f(tamX, tamY));
	movel = false;
}

Entidades::Obstaculos::Plataforma::~Plataforma()
{
}

void Entidades::Obstaculos::Plataforma::executar()
{
	Visual.setFillColor(sf::Color::Green);
	imprimir();
}
