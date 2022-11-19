#include "Fase1.h"

Fase1::Fase1(bool joga_dois):Fase(joga_dois)
{
	//Posic�o inicial dos jogadores
	jogador1->setX(0);
	jogador1->setY(640);
	if(joga_dois)
	{
		jogador2->setX(40);
		jogador2->setY(640);
	}

	//Adicionar plataformas
	Plataforma* plata = new Plataforma(0, 660, 2000, 100);
	Gerenciador_Colisoes::getInstance()->Adicionar(plata);
	todasEntis->List_Enti->Add(plata);
	plata = new Plataforma(80, 590, 250, 25);
	Gerenciador_Colisoes::getInstance()->Adicionar(plata);
	todasEntis->List_Enti->Add(plata);
	plata = new Plataforma(360, 540, 150, 25);
	Gerenciador_Colisoes::getInstance()->Adicionar(plata);
	todasEntis->List_Enti->Add(plata);
	plata = new Plataforma(560, 490, 300, 25);
	Gerenciador_Colisoes::getInstance()->Adicionar(plata);
	todasEntis->List_Enti->Add(plata);
}

Fase1::~Fase1()
{
}

void Fase1::GerarSoldados()
{
}
