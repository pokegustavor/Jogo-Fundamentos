#pragma once
#include "Ente.h"
#include "SFML/Graphics.hpp"
#include <iostream>
#include <fstream>
class Menu :
	public Ente
{
private:
	int Menu_Atual;
	bool graf_iniciado;
	bool holdingMouse;
	bool emFase;
	int fase;
public:
	Menu()
	{
		Menu_Atual = 0;
		fase = 0;
		graf_iniciado = false;
		holdingMouse = false;
		emFase = false;
	}
	~Menu()
	{

	}
	const bool getEmFase() { return emFase; };
	const int getFase() 
	{
		return fase;
	};
	void setEmFase(bool valor) { emFase = valor; };
	void executar()
	{
		if (!graf_iniciado)
		{
			grafico->Iniciar();
			graf_iniciado = true;
		}
		if (!holdingMouse)
		{
			switch (Menu_Atual)
			{
			case 0:
				if (sf::Mouse::isButtonPressed(sf::Mouse::Left) && sf::Mouse::getPosition(*grafico->Janela).x > 360.0f && sf::Mouse::getPosition(*grafico->Janela).x < 860.0f && sf::Mouse::getPosition(*grafico->Janela).y > 200.0f && sf::Mouse::getPosition(*grafico->Janela).y < 275.0f)
				{
					//Começar Jogo
					holdingMouse = true;
					Menu_Atual = 1;
				}
				if (sf::Mouse::isButtonPressed(sf::Mouse::Left) && sf::Mouse::getPosition(*grafico->Janela).x > 360.0f && sf::Mouse::getPosition(*grafico->Janela).x < 860.0f && sf::Mouse::getPosition(*grafico->Janela).y > 400.0f && sf::Mouse::getPosition(*grafico->Janela).y < 475.0f)
				{
					//Sair do jogo
					holdingMouse = true;
					grafico->Janela->close();
				}
				break;
			case 1:
				if (sf::Mouse::isButtonPressed(sf::Mouse::Left) && sf::Mouse::getPosition(*grafico->Janela).x > 360.0f && sf::Mouse::getPosition(*grafico->Janela).x < 860.0f && sf::Mouse::getPosition(*grafico->Janela).y > 200.0f && sf::Mouse::getPosition(*grafico->Janela).y < 275.0f)
				{
					//Fase 1
					fase = 1;
					emFase = true;
					Menu_Atual = 0;
				}
				if (sf::Mouse::isButtonPressed(sf::Mouse::Left) && sf::Mouse::getPosition(*grafico->Janela).x > 360.0f && sf::Mouse::getPosition(*grafico->Janela).x < 860.0f && sf::Mouse::getPosition(*grafico->Janela).y > 300.0f && sf::Mouse::getPosition(*grafico->Janela).y < 375.0f)
				{
					//Fase 2
					fase = 2;
					emFase = true;
					Menu_Atual = 0;
				}
				if (sf::Mouse::isButtonPressed(sf::Mouse::Left) && sf::Mouse::getPosition(*grafico->Janela).x > 360.0f && sf::Mouse::getPosition(*grafico->Janela).x < 860.0f && sf::Mouse::getPosition(*grafico->Janela).y > 400.0f && sf::Mouse::getPosition(*grafico->Janela).y < 475.0f)
				{
					//Retornar
					holdingMouse = true;
					Menu_Atual = 0;
				}
				break;
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
		sf::Text text = sf::Text("Jogar", font, 50);
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
			text.setString("Sair");
			grafico->Janela->draw(baseButton);
			grafico->Janela->draw(text);
			break;
		case 1:
			//Fase 1
			baseButton.setPosition(sf::Vector2f(360.0f, 200.0f));
			text.setFillColor(sf::Color::Black);
			text.setPosition(sf::Vector2f(535.0f, 200.0f));
			text.setString("Fase 1");
			grafico->Janela->draw(baseButton);
			grafico->Janela->draw(text);

			//Fase 2
			baseButton.setPosition(sf::Vector2f(360.0f, 300.0f));
			text.setFillColor(sf::Color::Black);
			text.setPosition(sf::Vector2f(535.0f, 300.0f));
			text.setString("Fase 2");
			grafico->Janela->draw(baseButton);
			grafico->Janela->draw(text);

			//Return
			baseButton.setPosition(sf::Vector2f(360.0f, 400.0f));
			text.setPosition(sf::Vector2f(535.0f, 400.0f));
			text.setString("Voltar");
			grafico->Janela->draw(baseButton);
			grafico->Janela->draw(text);
			break;
		};
		grafico->Janela->display();
	};
	sf::RenderWindow* getJanela() { return grafico->Janela; };
};