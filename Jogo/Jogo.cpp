#include "Jogo.h"
#include "SFML/Graphics.hpp"

Jogo* Jogo::_instance = new Jogo();
Gerenciador_Colisoes* Gerenciador_Colisoes::_instance = new Gerenciador_Colisoes();
int main()
{
	Jogo::getInstance()->Executar();
	return 0;
}

Jogo::Jogo()
{
	nextID = 0;
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
		if (!menu->emFase)
		{
			menu->executar();
		}
		else
		{
			if (fase == nullptr)
			{
				fase = new Fase1(false);
			}
			fase->executar();
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
			{
				menu->emFase = false;
				delete fase;
				fase = nullptr;
			}
		}
	}
}
