#pragma once
#include "SFML//Graphics.hpp"
class Gerenciador_Grafico
{
private:
    static Gerenciador_Grafico* _instance;
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
        Janela = new sf::RenderWindow(sf::VideoMode(2000, 500), "Jogo!");
	}
    static Gerenciador_Grafico* getInstance()
    {
        return _instance;
    }
};

