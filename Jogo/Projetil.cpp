#include "Projetil.h"


Projetil::Projetil(int posX, int posY, int DireX, int DireY) :Entidade(posX, posY), velocidade(20)
{
	Visual.setSize(sf::Vector2f(5.f, 5.f));
	inativo = false;
	direX = DireX/velocidade;
	direY = DireY/velocidade;
}

Projetil::~Projetil()
{
}

void Projetil::setPostion(int X, int Y)
{
	x = X;
	y = Y;
}

void Projetil::setDirection(int X, int Y)
{
	direX = X/velocidade;
	direY = Y/velocidade;
}

void Projetil::executar()
{
	if (inativo)return;
	Visual.setFillColor(sf::Color::White);
	x += direX;
	y += direY;
	if (x < 0 || y < 0 || x > grafico->Janela->getSize().x || y > grafico->Janela->getSize().y)inativo = true;
	imprimir();
}

void Projetil::setInativo(bool inatividade)
{
	inativo = inatividade;
}

bool Projetil::getInativo()
{
	return inativo;
}
