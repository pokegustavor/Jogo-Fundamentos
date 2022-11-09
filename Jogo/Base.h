#pragma once
#include "SFML/Graphics.hpp"
class Base
{
protected:
	int id;
	sf::RectangleShape Visual;
public:
	Base();
	~Base();
	virtual void executar() = 0;
	virtual void imprimir() = 0;
	const int getID();
};

