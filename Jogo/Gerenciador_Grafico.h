#pragma once
#include "SFML//Graphics.hpp"
class Gerenciador_Grafico
{
private:
public:
	sf::RenderWindow* Janela;
	Gerenciador_Grafico()
	{
		Janela = nullptr;
	}
	~Gerenciador_Grafico()
	{

	}
	void Iniciar()
	{
        Janela = new sf::RenderWindow(sf::VideoMode(2000, 500), "Jogo!", sf::Style::Titlebar | sf::Style::Close);
		Janela->setFramerateLimit(30);
	}
};

