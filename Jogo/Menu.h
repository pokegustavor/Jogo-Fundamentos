#pragma once
#include "Ente.h"
#include "SFML/Graphics.hpp"
#include <iostream>
#include <fstream>
#include "Jogo.h"
class Menu :
	public Ente
{
private:
	int Menu_Atual;
	bool graf_iniciado;
	bool holdingMouse;
public:
	bool emFase;
	Menu()
	{
		Menu_Atual = 0;
		graf_iniciado = false;
		holdingMouse = false;
		emFase = false;
	}
	~Menu()
	{

	}
	void executar()
	{
		if (!graf_iniciado)
		{
			grafico->Iniciar();
			graf_iniciado = true;
		}
		if (!holdingMouse)
		{
			if (sf::Mouse::isButtonPressed(sf::Mouse::Left) && sf::Mouse::getPosition(*grafico->Janela).x > 360.0f && sf::Mouse::getPosition(*grafico->Janela).x < 860.0f && sf::Mouse::getPosition(*grafico->Janela).y > 200.0f && sf::Mouse::getPosition(*grafico->Janela).y < 275.0f)
			{
				//Começar Jogo
				holdingMouse = true;
				emFase = true;
			}
			if (sf::Mouse::isButtonPressed(sf::Mouse::Left) && sf::Mouse::getPosition(*grafico->Janela).x > 360.0f && sf::Mouse::getPosition(*grafico->Janela).x < 860.0f && sf::Mouse::getPosition(*grafico->Janela).y > 400.0f && sf::Mouse::getPosition(*grafico->Janela).y < 475.0f)
			{
				//Sair do jogo
				holdingMouse = true;
				grafico->Janela->close();
			}
		}
		if (!sf::Mouse::isButtonPressed(sf::Mouse::Left))
		{
			holdingMouse = false;
		}
		imprimir();
	};
	void imprimir()
	{
		sf::Event event;
		while (grafico->Janela->pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				grafico->Janela->close();
		}
		grafico->Janela->clear();
		sf::RectangleShape background = sf::RectangleShape(sf::Vector2f(1600.0f, 800.0f));
		background.setFillColor(sf::Color::Black);
		grafico->Janela->draw(background);
		sf::Font font;
		font.loadFromFile("arial.ttf");
		sf::Text title = sf::Text("Jogo", font, 100);
		sf::RectangleShape baseButton = sf::RectangleShape(sf::Vector2f(500.0f, 75.0f));
		sf::Text text = sf::Text("Play", font, 50);
		sf::RectangleShape button = sf::RectangleShape(sf::Vector2f(100.0f, 100.0f));
		button.setFillColor(sf::Color::White);
		sf::RectangleShape button2 = sf::RectangleShape(sf::Vector2f(75.0f, 75.0f));
		button2.setFillColor(sf::Color::Black);
		switch (Menu_Atual)
		{
		case 0:
			//Titulo
			title.setOutlineColor(sf::Color::Red);
			title.setFillColor(sf::Color::Red);
			title.setPosition(sf::Vector2f(510.0f, 50.0f));
			grafico->Janela->draw(title);

			//Play
			baseButton.setPosition(sf::Vector2f(360.0f, 200.0f));
			text.setFillColor(sf::Color::Black);
			text.setPosition(sf::Vector2f(570.0f, 200.0f));
			grafico->Janela->draw(baseButton);
			grafico->Janela->draw(text);

			//Ranking
			baseButton.setPosition(sf::Vector2f(360.0f, 300.0f));
			text.setPosition(sf::Vector2f(530.0f, 300.0f));
			text.setString("Ranking");
			grafico->Janela->draw(baseButton);
			grafico->Janela->draw(text);

			//Exit
			baseButton.setPosition(sf::Vector2f(360.0f, 400.0f));
			text.setPosition(sf::Vector2f(570.0f, 400.0f));
			text.setString("Exit");
			grafico->Janela->draw(baseButton);
			grafico->Janela->draw(text);
			break;
			
		};
		grafico->Janela->display();
	};
	sf::RenderWindow* getJanela() { return grafico->Janela; };
};