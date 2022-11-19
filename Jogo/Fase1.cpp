#include "Fase1.h"

Fase1::Fase1(bool joga_dois):Fase(joga_dois)
{
	//Posicão inicial dos jogadores
	jogador1->setX(0);
	jogador1->setY(380);
	if(joga_dois)
	{
		jogador2->setX(40);
		jogador2->setY(380);
	}

	//Adicionar plataformas
	Plataforma* plata = new Plataforma(0, 400, 2000, 100);
	Gerenciador_Colisoes::getInstance()->Adicionar(plata);
	todasEntis->List_Enti->Add(plata);
	plata = new Plataforma(80, 330, 250, 25);
	Gerenciador_Colisoes::getInstance()->Adicionar(plata);
	todasEntis->List_Enti->Add(plata);
}

Fase1::~Fase1()
{
}
