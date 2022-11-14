#include "Entidade.h"
Entidades::Entidade::Entidade(int X,int Y)
{
	id = -1;
	x = X;
	y = Y;
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
