#include "Jogo.h"
#include "SFML/Graphics.hpp"
Jogo* Jogo::_instance = new Jogo();
Gerenciador_Colisoes* Gerenciador_Colisoes::_instance = new Gerenciador_Colisoes();
int main()
{
	srand(time(0));
	Jogo::getInstance()->Executar();
	return 0;
}

Jogo::Jogo()
{
	nextID = 0;
	level = 0;
	menu = new Menu();
	jogando = false;
	fase = nullptr;
}
Jogo::~Jogo()
{
}
Jogo* Jogo::getInstance()
{
	return _instance;
}

int Jogo::GetNextFreeID()
{
	nextID++;
	return nextID - 1;
}

void Jogo::Executar()
{
	menu->executar();
	sf::RenderWindow* Janela = menu->getJanela();
	while (Janela->isOpen())
	{
		sf::Event event;
		while (Janela->pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				Janela->close();
		}
		if (!menu->getEmFase())
		{
			menu->executar();
		}
		else
		{
			if (fase == nullptr)
			{
				if(menu->getFase() == 1)fase = new Fase1(false);
				else if (menu->getFase() == 2)fase = new Fase2(false);
			}
			fase->executar();
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape) || fase->completa())
			{
				menu->setEmFase(false);
				delete fase;
				fase = nullptr;
			}
		}
	}
}

Fase* Jogo::getFase()
{
	return fase;
}
