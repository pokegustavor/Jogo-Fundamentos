#include "Atirador.h"

Entidades::Personagems::Atirador::Atirador(const int X, const int Y):Inimigo(X,Y)
{
	Visual.setSize(sf::Vector2f(20.f, 20.f));
	meu_Projetil = new Projetil(X,Y,0,0);
	meu_Projetil->setInativo(true);
}

Entidades::Personagems::Atirador::~Atirador()
{
}

void Entidades::Personagems::Atirador::executar()
{
	if (morto)return;
	Visual.setFillColor(sf::Color::Magenta);
	Personagem::executar();
	try
	{
		if (meu_Projetil != nullptr && meu_Projetil->getInativo() && abs(Alvo->getX() - x) < 200 && abs(Alvo->getY() - y) < 150)
		{
			meu_Projetil->setPostion(x + Visual.getSize().x / 2, y + Visual.getSize().y / 2);
			meu_Projetil->setDirection(((Alvo->getX() + Visual.getSize().x / 2) - (x + Visual.getSize().x / 2)), ((Alvo->getY() + Visual.getSize().y / 2) - (y + Visual.getSize().y / 2)));
			meu_Projetil->setInativo(false);
		}
	}
	catch(int*)
	{
		if(meu_Projetil != nullptr)
		{
			meu_Projetil->setInativo(true);
		}
	}
	if (!noChao && deltaY <= 3)
	{
		deltaY += 2;
	}
	noChao = false;
	if (deltaX > 4)deltaX = 4;
	if (deltaX < -4)deltaX = -4;
}

Entidades::Projetil* Entidades::Personagems::Atirador::getProjetil()
{
	return meu_Projetil;
}

void Entidades::Personagems::Atirador::Danar(Jogador* alvo)
{
	alvo->receberDano(1);
}
