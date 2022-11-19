#include "Obstaculo.h"

Entidades::Obstaculos::Obstaculo::Obstaculo(int X, int Y):Entidade(X,Y)
{
	Perigoso = false;
	Danificavel = false;
}

Entidades::Obstaculos::Obstaculo::~Obstaculo()
{
}

void Entidades::Obstaculos::Obstaculo::Danar(Jogador* alvo)
{
}
