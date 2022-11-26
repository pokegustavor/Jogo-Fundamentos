#include "Plataforma.h"

Entidades::Obstaculos::Plataforma::Plataforma(const int X,const int Y,const int tamX,const int tamY,const bool Movel):Obstaculo(X,Y)
{
	Visual.setSize(sf::Vector2f(tamX, tamY));
	movel = Movel;
	subindo = true;
	meio = Y;
}

Entidades::Obstaculos::Plataforma::~Plataforma()
{
}

void Entidades::Obstaculos::Plataforma::executar()
{
	Visual.setFillColor(sf::Color::Green);
	if(movel)
	{
		if(subindo)
		{
			y--;
			if (meio - y > 80)subindo = false;
		}
		else
		{
			y++;
			if (y - meio > 80)subindo = true;
		}
	}
	imprimir();
}

const bool Entidades::Obstaculos::Plataforma::getMovel()
{
	return movel;
}

const bool Entidades::Obstaculos::Plataforma::getSubindo()
{
	return subindo;
}

void Entidades::Obstaculos::Plataforma::Bloquear(Entidade* enti, const Direcao dire)
{
	Personagem* persona = dynamic_cast<Personagem*>(enti);
	switch (dire)
	{
	case Cima:
		enti->setY(y - enti->Visual.getSize().y);
		if(movel && subindo)enti->setDeltaY(-1);
		else enti->setDeltaY(0);
		if(persona != nullptr)persona->setChao(true);
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
}
