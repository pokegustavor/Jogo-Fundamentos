#include "Caixa.h"

Entidades::Obstaculos::Caixa::Caixa(int X, int Y):Obstaculo(X,Y)
{
	Visual.setSize(sf::Vector2f(15.f, 15.f));
	Danificavel = true;
	Tem_Item = true;// rand() % 4 == 0;
	Quebrada = false;
}
Entidades::Obstaculos::Caixa::~Caixa()
{
}

void Entidades::Obstaculos::Caixa::executar()
{
	if (Quebrada)return;
	Visual.setFillColor(sf::Color::Yellow);
	imprimir();
}

void Entidades::Obstaculos::Caixa::quebrar()
{
	Quebrada = true;
}

const bool Entidades::Obstaculos::Caixa::getItem()
{
	return Tem_Item;
}

const bool Entidades::Obstaculos::Caixa::getQuebrada()
{
	return Quebrada;
}
