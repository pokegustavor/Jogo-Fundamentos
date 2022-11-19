#include "Projetil.h"


Entidades::Projetil::Projetil(int posX, int posY, int DireX, int DireY) :Entidade(posX, posY), velocidade(20)
{
	Visual.setSize(sf::Vector2f(5.f, 5.f));
	inativo = false;
	direX = DireX/velocidade;
	direY = DireY/velocidade;
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
	direX = X/velocidade;
	direY = Y/velocidade;
}

void Entidades::Projetil::executar()
{
	if (inativo)return;
	Visual.setFillColor(sf::Color::White);
	x += direX;
	y += direY;
	if (x < 0 || y < 0 || x > grafico->Janela->getSize().x || y > grafico->Janela->getSize().y)inativo = true;
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
