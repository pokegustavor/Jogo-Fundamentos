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
	bool doisJoga;
public:
	Menu()
	{
		Menu_Atual = 0;
		fase = 0;
		graf_iniciado = false;
		holdingMouse = false;
		emFase = false;
		doisJoga = false;
	}
	~Menu()
	{

	}
	const bool getEmFase() { return emFase; };
	const int getFase() 
	{
		return fase;
	};
	void setEmFase(const bool valor) { emFase = valor; };
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
				if (sf::Mouse::isButtonPressed(sf::Mouse::Left) && sf::Mouse::getPosition(*grafico->getJanela()).x > 360.0f && sf::Mouse::getPosition(*grafico->getJanela()).x < 860.0f && sf::Mouse::getPosition(*grafico->getJanela()).y > 200.0f && sf::Mouse::getPosition(*grafico->getJanela()).y < 275.0f)
				{
					//Começar Jogo
					holdingMouse = true;
					Menu_Atual = 1;
				}
				if (sf::Mouse::isButtonPressed(sf::Mouse::Left) && sf::Mouse::getPosition(*grafico->getJanela()).x > 360.0f && sf::Mouse::getPosition(*grafico->getJanela()).x < 860.0f && sf::Mouse::getPosition(*grafico->getJanela()).y > 300.0f && sf::Mouse::getPosition(*grafico->getJanela()).y < 375.0f)
				{
					//Ranking
					holdingMouse = true;
					Menu_Atual = 2;
				}
				if (sf::Mouse::isButtonPressed(sf::Mouse::Left) && sf::Mouse::getPosition(*grafico->getJanela()).x > 360.0f && sf::Mouse::getPosition(*grafico->getJanela()).x < 860.0f && sf::Mouse::getPosition(*grafico->getJanela()).y > 400.0f && sf::Mouse::getPosition(*grafico->getJanela()).y < 475.0f)
				{
					//Sair do jogo
					holdingMouse = true;
					grafico->getJanela()->close();
				}
				break;
			case 1:
				if (sf::Mouse::isButtonPressed(sf::Mouse::Left) && sf::Mouse::getPosition(*grafico->getJanela()).x > 360.0f && sf::Mouse::getPosition(*grafico->getJanela()).x < 860.0f && sf::Mouse::getPosition(*grafico->getJanela()).y > 100.0f && sf::Mouse::getPosition(*grafico->getJanela()).y < 175.0f)
				{
					//Dois Jogadores
					doisJoga = !doisJoga;
					holdingMouse = true;
				}
				if (sf::Mouse::isButtonPressed(sf::Mouse::Left) && sf::Mouse::getPosition(*grafico->getJanela()).x > 360.0f && sf::Mouse::getPosition(*grafico->getJanela()).x < 860.0f && sf::Mouse::getPosition(*grafico->getJanela()).y > 200.0f && sf::Mouse::getPosition(*grafico->getJanela()).y < 275.0f)
				{
					//Fase 1
					fase = 1;
					emFase = true;
					Menu_Atual = 0;
				}
				if (sf::Mouse::isButtonPressed(sf::Mouse::Left) && sf::Mouse::getPosition(*grafico->getJanela()).x > 360.0f && sf::Mouse::getPosition(*grafico->getJanela()).x < 860.0f && sf::Mouse::getPosition(*grafico->getJanela()).y > 300.0f && sf::Mouse::getPosition(*grafico->getJanela()).y < 375.0f)
				{
					//Fase 2
					fase = 2;
					emFase = true;
					Menu_Atual = 0;
				}
				if (sf::Mouse::isButtonPressed(sf::Mouse::Left) && sf::Mouse::getPosition(*grafico->getJanela()).x > 360.0f && sf::Mouse::getPosition(*grafico->getJanela()).x < 860.0f && sf::Mouse::getPosition(*grafico->getJanela()).y > 400.0f && sf::Mouse::getPosition(*grafico->getJanela()).y < 475.0f)
				{
					//Retornar
					holdingMouse = true;
					Menu_Atual = 0;
				}
				break;
			case 2:
				if (sf::Mouse::isButtonPressed(sf::Mouse::Left) && sf::Mouse::getPosition(*grafico->getJanela()).x > 360.0f && sf::Mouse::getPosition(*grafico->getJanela()).x < 860.0f && sf::Mouse::getPosition(*grafico->getJanela()).y > 500.0f && sf::Mouse::getPosition(*grafico->getJanela()).y < 575.0f)
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
		while (grafico->getJanela()->pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				grafico->getJanela()->close();
		}
		grafico->getJanela()->clear();
		sf::RectangleShape background = sf::RectangleShape(sf::Vector2f(1600.0f, 800.0f));
		background.setFillColor(sf::Color::Black);
		grafico->getJanela()->draw(background);
		sf::Font font;
		font.loadFromFile("arial.ttf");
		sf::Text title = sf::Text("Combatente--", font, 100);
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
			title.setPosition(sf::Vector2f(315.0f, 50.0f));
			grafico->getJanela()->draw(title);

			//Play
			baseButton.setPosition(sf::Vector2f(360.0f, 200.0f));
			text.setFillColor(sf::Color::Black);
			text.setPosition(sf::Vector2f(550.0f, 200.0f));
			grafico->getJanela()->draw(baseButton);
			grafico->getJanela()->draw(text);

			//Ranking
			baseButton.setPosition(sf::Vector2f(360.0f, 300.0f));
			text.setPosition(sf::Vector2f(530.0f, 300.0f));
			text.setString("Ranking");
			grafico->getJanela()->draw(baseButton);
			grafico->getJanela()->draw(text);

			//Exit
			baseButton.setPosition(sf::Vector2f(360.0f, 400.0f));
			text.setPosition(sf::Vector2f(570.0f, 400.0f));
			text.setString("Sair");
			grafico->getJanela()->draw(baseButton);
			grafico->getJanela()->draw(text);
			break;
		case 1:
			//Dois joga
			baseButton.setPosition(sf::Vector2f(360.0f, 100.0f));
			text.setPosition(sf::Vector2f(470.0f, 100.0f));
			text.setString("2 Jogadores");
			if(doisJoga)
			{
				text.setFillColor(sf::Color::Green);
			}
			else
			{
				text.setFillColor(sf::Color::Red);
			}
			grafico->getJanela()->draw(baseButton);
			grafico->getJanela()->draw(text);

			//Fase 1
			baseButton.setPosition(sf::Vector2f(360.0f, 200.0f));
			text.setFillColor(sf::Color::Black);
			text.setPosition(sf::Vector2f(535.0f, 200.0f));
			text.setString("Fase 1");
			grafico->getJanela()->draw(baseButton);
			grafico->getJanela()->draw(text);

			//Fase 2
			baseButton.setPosition(sf::Vector2f(360.0f, 300.0f));
			text.setFillColor(sf::Color::Black);
			text.setPosition(sf::Vector2f(535.0f, 300.0f));
			text.setString("Fase 2");
			grafico->getJanela()->draw(baseButton);
			grafico->getJanela()->draw(text);

			//Return
			baseButton.setPosition(sf::Vector2f(360.0f, 400.0f));
			text.setPosition(sf::Vector2f(535.0f, 400.0f));
			text.setString("Voltar");
			grafico->getJanela()->draw(baseButton);
			grafico->getJanela()->draw(text);
			break;
		case 2:
			text.setFillColor(sf::Color::White);
			text.setPosition(sf::Vector2f(470.0f, 100.0f));
			text.setString("1st WIP: 9999");
			grafico->getJanela()->draw(text);
			text.setPosition(sf::Vector2f(470.0f, 200.0f));
			text.setString("2nd WIP: 9999");
			grafico->getJanela()->draw(text);
			text.setPosition(sf::Vector2f(470.0f, 300.0f));
			text.setString("3rd WIP: 9999");
			grafico->getJanela()->draw(text);
			text.setPosition(sf::Vector2f(470.0f, 400.0f));
			text.setString("4th WIP: 9999");
			grafico->getJanela()->draw(text);
			text.setFillColor(sf::Color::Black);
			//Return
			baseButton.setPosition(sf::Vector2f(360.0f, 500.0f));
			text.setPosition(sf::Vector2f(535.0f, 500.0f));
			text.setString("Voltar");
			grafico->getJanela()->draw(baseButton);
			grafico->getJanela()->draw(text);
			break;
		};
		grafico->mostarJanela();
	};
	const bool getDoisJogadores()
	{
		return doisJoga;
	}
	sf::RenderWindow* getJanela() { return grafico->getJanela(); };
};