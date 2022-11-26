#include "Colosso.h"
#include "Jogo.h"

Entidades::Personagems::Colosso::Colosso(int X, int Y):Inimigo(X,Y)
{
	ultimoSolda = clock();
	chefao = true;
	rapido = rand() % 5 == 0;
	Visual.setSize(sf::Vector2f(30.f, 40.f));
}

Entidades::Personagems::Colosso::~Colosso()
{
}

void Entidades::Personagems::Colosso::executar()
{
	if (morto)return;
	Visual.setFillColor(sf::Color::Cyan);
	Personagem::executar();
	int tempo = rapido ? 2 : 5;
	clock_t now = clock();
	float timer = float(now - ultimoSolda) / CLOCKS_PER_SEC;
	if(timer > tempo)
	{
		Soldado* solda = new Soldado(x, y-20);
		solda->SetAlvo(Alvo);
		Jogo::getInstance()->getFase()->adicionar(solda);
		ultimoSolda = now;
	}
	if (!noChao && deltaY <= 3)
	{
		deltaY += 2;
	}
	noChao = false;
	if (deltaX > 4)deltaX = 4;
	if (deltaX < -4)deltaX = -4;
}

void Entidades::Personagems::Colosso::Danar(Jogador* alvo)
{
	alvo->receberDano(2);
}
