#include "Ente.h"
Gerenciador_Grafico* Ente::grafico = new Gerenciador_Grafico();
Ente::Ente():Visual(sf::Vector2f(500.0f,500.0f))
{
	id = -1;
}
Ente::~Ente() {}
const int Ente::getID()
{
	return id;
}
