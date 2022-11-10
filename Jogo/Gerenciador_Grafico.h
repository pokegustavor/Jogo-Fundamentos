#pragma once
#include "SFML//Graphics.hpp"
class Gerenciador_Grafico
{
private:
    static Gerenciador_Grafico* _instance;
	Gerenciador_Grafico()
	{
		Janela = nullptr;
	}
	~Gerenciador_Grafico()
	{

	}
public:
	sf::RenderWindow* Janela;
	void Iniciar()
	{
        Janela = new sf::RenderWindow(sf::VideoMode(2000, 500), "Jogo!", sf::Style::Titlebar | sf::Style::Close);
		Janela->setFramerateLimit(30);
	}
    static Gerenciador_Grafico* getInstance()
    {
        return _instance;
    }
};

