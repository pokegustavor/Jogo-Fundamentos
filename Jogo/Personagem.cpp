#include "Personagem.h"

Entidades::Personagems::Personagem::Personagem(int X, int Y):Entidade(X,Y)
{
	vida = 1;
	morto = false;
	Visual.setFillColor(sf::Color::Cyan);
	noChao = false;
}

Entidades::Personagems::Personagem::~Personagem()
{
}

void Entidades::Personagems::Personagem::executar()
{
	x += deltaX;
	y += deltaY;
	if (x < 0)x = 0;
	if (y < 0)y = 0;
	if (x + Visual.getSize().x > grafico->Janela->getSize().x)x = grafico->Janela->getSize().x - Visual.getSize().x;
	if (y + Visual.getSize().y > grafico->Janela->getSize().y)y = grafico->Janela->getSize().y - Visual.getSize().y;
	if(vida <= 0)
	{
		morto = true;
	}
	imprimir();
}

void Entidades::Personagems::Personagem::receberDano(int valor)
{
	vida -= valor;
	if (vida <= 0)morto = true;
}

void Entidades::Personagems::Personagem::setChao(bool chao)
{
	noChao = chao;
}

const bool Entidades::Personagems::Personagem::getMorto()
{
	return morto;
}

const int Entidades::Personagems::Personagem::getVidas()
{
	return vida;
}
