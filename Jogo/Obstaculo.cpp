#include "Obstaculo.h"

Entidades::Obstaculos::Obstaculo::Obstaculo(int X, int Y):Entidade(X,Y)
{
	Danificavel = false;
}

Entidades::Obstaculos::Obstaculo::~Obstaculo()
{
}

void Entidades::Obstaculos::Obstaculo::Danar(Jogador* alvo)
{
}

const bool Entidades::Obstaculos::Obstaculo::getDanifica()
{
	return Danificavel;
}
