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

void Entidades::Obstaculos::Espinho::Bloquear(Entidade* enti, Direcao dire)
{
	Jogador* persona = dynamic_cast<Jogador*>(enti);
	switch (dire)
	{
	case Cima:
		enti->setY(y - enti->Visual.getSize().y);
		enti->setDeltaY(0);
		break;
	case Baixo:
		enti->setY(y + Visual.getSize().y);
		enti->setDeltaY(0);
		break;
	case Direita:
		enti->setX(x + Visual.getSize().x);
		enti->setDeltaX(0);
		break;
	case Esquerda:
		enti->setX(x - enti->Visual.getSize().x);
		enti->setDeltaX(0);
		break;
	}
	if(persona != nullptr)
	{
		persona->receberDano(1);
	}
}
