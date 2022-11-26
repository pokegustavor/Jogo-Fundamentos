#include "Obstaculo.h"
#include "Gerenciador_Colisoes.h"

Entidades::Obstaculos::Obstaculo::Obstaculo(const int X, const int Y):Entidade(X,Y)
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
