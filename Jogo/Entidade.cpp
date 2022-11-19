#include "Entidade.h"
Entidades::Entidade::Entidade(int X,int Y)
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
	grafico->Janela->draw(Visual);
}

int Entidades::Entidade::getX()
{
	return x;
}

int Entidades::Entidade::getY()
{
	return y;
}

int Entidades::Entidade::getDeltaX()
{
	return deltaX;
}

int Entidades::Entidade::getDeltaY()
{
	return deltaY;
}

void Entidades::Entidade::setX(int X)
{
	x = X;
}

void Entidades::Entidade::setY(int Y)
{
	y = Y;
}

void Entidades::Entidade::setDeltaX(int X)
{
	deltaX = X;
}

void Entidades::Entidade::setDeltaY(int Y)
{
	deltaY = Y;
}
