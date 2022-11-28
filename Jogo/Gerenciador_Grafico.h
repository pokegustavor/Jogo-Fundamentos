#pragma once
#include "SFML//Graphics.hpp"
namespace Gerenciadores
{
	class Gerenciador_Grafico
	{
	private:
		sf::RenderWindow* Janela;
	public:
		Gerenciador_Grafico()
		{
			Janela = nullptr;
		}
		~Gerenciador_Grafico()
		{

		}
		void Iniciar()
		{
			Janela = new sf::RenderWindow(sf::VideoMode(1280, 720), "Combatente--", sf::Style::Titlebar | sf::Style::Close);
			Janela->setFramerateLimit(60);
		}
		sf::RenderWindow* getJanela()
		{
			return Janela;
		}
		void mostarJanela()
		{
			Janela->display();
		}
	};
}

