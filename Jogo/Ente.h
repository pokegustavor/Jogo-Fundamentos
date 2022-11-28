#pragma once
#include "SFML/Graphics.hpp"
#include "Gerenciador_Grafico.h"
using namespace Gerenciadores;
class Ente
{
protected:
	int id;
	static Gerenciador_Grafico* grafico;
public:
	Ente();
	~Ente();
	virtual void executar() = 0;
	virtual void imprimir() = 0;
	const int getID();
	sf::RectangleShape Visual;
};

