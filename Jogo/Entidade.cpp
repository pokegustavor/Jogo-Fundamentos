#include "Entidade.h"
Entidades::Entidade::Entidade(const int X,const int Y)
{
	id = -1;
	x = X;
	y = Y;
	deltaX = 0;
	deltaY = 0;
}
Entidades::Entidade::~Entidade()
{

}

void Entidades::Entidade::imprimir()
{
	Visual.setPosition(sf::Vector2f((float)x, (float)y));
	grafico->getJanela()->draw(Visual);
}

const int Entidades::Entidade::getX()
{
	return x;
}

const int Entidades::Entidade::getY()
{
	return y;
}

const int Entidades::Entidade::getDeltaX()
{
	return deltaX;
}

const int Entidades::Entidade::getDeltaY()
{
	return deltaY;
}

void Entidades::Entidade::setX(const int X)
{
	x = X;
}

void Entidades::Entidade::setY(const int Y)
{
	y = Y;
}

void Entidades::Entidade::setDeltaX(const int X)
{
	deltaX = X;
}

void Entidades::Entidade::setDeltaY(const int Y)
{
	deltaY = Y;
}
