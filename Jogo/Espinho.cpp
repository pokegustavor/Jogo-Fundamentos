#include "Espinho.h"

Entidades::Obstaculos::Espinho::Espinho(int X, int Y):Obstaculo(X,Y)
{
	Visual.setSize(sf::Vector2f(20, 20));
	afiado = rand() % 4 == 0;
	Visual.setRotation(45);
}

Entidades::Obstaculos::Espinho::~Espinho()
{
}

void Entidades::Obstaculos::Espinho::Danar(Jogador* alvo)
{
	alvo->receberDano((afiado ? 2 : 1));
}

void Entidades::Obstaculos::Espinho::executar()
{
	Visual.setFillColor(sf::Color::Red);
	imprimir();
}
