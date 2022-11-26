#include "Projetil.h"


Entidades::Projetil::Projetil(int posX, int posY, int DireX, int DireY) :Entidade(posX, posY), velocidade(8)
{
	Visual.setSize(sf::Vector2f(5.f, 5.f));
	inativo = false;
	while (abs(DireX) > velocidade || abs(DireY) > velocidade)
	{
		DireX /= 2;
		DireY /= 2;
	}
	direX = DireX;
	direY = DireY;
}

Entidades::Projetil::~Projetil()
{
}

void Entidades::Projetil::setPostion(int X, int Y)
{
	x = X;
	y = Y;
}

void Entidades::Projetil::setDirection(int X, int Y)
{
	while(abs(X) > velocidade || abs(Y) > velocidade)
	{
		X /= 2;
		Y /= 2;
	}
	direX = X;
	direY = Y;
}

void Entidades::Projetil::executar()
{
	if (inativo)return;
	Visual.setFillColor(sf::Color::White);
	x += direX;
	y += direY;
	if (x < 0 || y < 0 || x > grafico->getJanela()->getSize().x || y > grafico->getJanela()->getSize().y)inativo = true;
	imprimir();
}

void Entidades::Projetil::setInativo(bool inatividade)
{
	inativo = inatividade;
}

bool Entidades::Projetil::getInativo()
{
	return inativo;
}
