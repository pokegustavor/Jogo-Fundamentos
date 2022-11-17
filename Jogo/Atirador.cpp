#include "Atirador.h"

Atirador::Atirador():Inimigo(250,80)
{
	Visual.setSize(sf::Vector2f(20.f, 20.f));
	meu_Projetil = nullptr;
}

Atirador::~Atirador()
{
	delete meu_Projetil;
}

void Atirador::executar()
{
	if(meu_Projetil == nullptr && Alvo != nullptr)
	{
		meu_Projetil = new Projetil(x + Visual.getSize().x/2, y + Visual.getSize().y/2, (Alvo->getX() + Visual.getSize().x / 2) - (x + Visual.getSize().x / 2), (Alvo->getY() + Visual.getSize().y / 2) - (y + Visual.getSize().y / 2));
	}
	if(meu_Projetil->getInativo())
	{
		meu_Projetil->setPostion(x + Visual.getSize().x/2,y + Visual.getSize().y/2);
		meu_Projetil->setDirection((Alvo->getX() + Visual.getSize().x/2) - (x + Visual.getSize().x / 2), (Alvo->getY() + Visual.getSize().y/2) - (y + Visual.getSize().y / 2));
		meu_Projetil->setInativo(false);
	}
	Visual.setFillColor(sf::Color::Magenta);
	Personagem::executar();
}

Projetil* Atirador::getProjetil()
{
	return meu_Projetil;
}
