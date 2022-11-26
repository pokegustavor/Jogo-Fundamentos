#include "Caixa.h"

Entidades::Obstaculos::Caixa::Caixa(const int X,const int Y):Obstaculo(X,Y)
{
	Visual.setSize(sf::Vector2f(15.f, 15.f));
	Danificavel = true;
	Tem_Item = rand() % 4 == 0;
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

void Entidades::Obstaculos::Caixa::Bloquear(Entidade* enti, Direcao dire)
{
	Personagem* persona = dynamic_cast<Personagem*>(enti);
	Jogador* joga = dynamic_cast<Jogador*>(enti);
	switch (dire)
	{
	case Cima:
		enti->setY(y - enti->Visual.getSize().y);
		enti->setDeltaY(0);
		if (persona != nullptr)persona->setChao(true);
		break;
	case Baixo:
		if(joga != nullptr)
		{
			Quebrada = true;
			if(Tem_Item)joga->invunerar();
		}
		else
		{
			enti->setY(y + Visual.getSize().y);
		}
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
}
