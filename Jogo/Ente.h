#pragma once
#include "SFML/Graphics.hpp"
class Ente
{
protected:
	int id;
	
public:
	Ente();
	~Ente();
	virtual void executar() = 0;
	virtual void imprimir() = 0;
	const int getID();
	sf::RectangleShape Visual;
};
