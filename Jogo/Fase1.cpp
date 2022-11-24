#include "Fase1.h"

Fases::Fase1::Fase1(bool joga_dois):Fase(joga_dois)
{
	//Posicão inicial dos jogadores
	jogador1->setX(0);
	jogador1->setY(640);
	if(joga_dois)
	{
		jogador2->setX(40);
		jogador2->setY(640);
	}

	//Adicionar Obstaculos
	Plataforma* plata = new Plataforma(0, 660, 2000, 100);
	Gerenciador_Colisoes::getInstance()->Adicionar(plata);
	todasEntis->List_Enti->AddFront(plata);
	plata = new Plataforma(80, 590, 250, 25);
	Gerenciador_Colisoes::getInstance()->Adicionar(plata);
	todasEntis->List_Enti->AddFront(plata);
	plata = new Plataforma(360, 540, 150, 25);
	Gerenciador_Colisoes::getInstance()->Adicionar(plata);
	todasEntis->List_Enti->AddFront(plata);
	plata = new Plataforma(560, 400, 300, 25,true);
	Gerenciador_Colisoes::getInstance()->Adicionar(plata);
	todasEntis->List_Enti->AddFront(plata);
	plata = new Plataforma(0, 440, 490, 25);
	Gerenciador_Colisoes::getInstance()->Adicionar(plata);
	todasEntis->List_Enti->AddFront(plata);
	plata = new Plataforma(910, 440, 450, 25);
	Gerenciador_Colisoes::getInstance()->Adicionar(plata);
	todasEntis->List_Enti->AddFront(plata);
	plata = new Plataforma(900, 540, 250, 25);
	Gerenciador_Colisoes::getInstance()->Adicionar(plata);
	todasEntis->List_Enti->AddFront(plata);
	plata = new Plataforma(560, 590, 300, 25);
	Gerenciador_Colisoes::getInstance()->Adicionar(plata);
	todasEntis->List_Enti->AddFront(plata);
	GerarEspinhos();


	//Adicionar inimigos
	GerarAtiradores();
	GerarSoldados();
}

Fases::Fase1::~Fase1()
{
}

void Fases::Fase1::GerarSoldados()
{
	int total = (rand() % 7) + 3;
	Soldado* solda = nullptr;
	for(int i = 0; i <= total;i++)
	{
		solda = new Soldado((rand() % 800) + 100, (rand() % 220) + 420);
		solda->SetAlvo(jogador1);
		Gerenciador_Colisoes::getInstance()->Adicionar(solda);
		todasEntis->List_Enti->Add(solda);
	}
}

void Fases::Fase1::GerarAtiradores()
{
	int total = (rand() % 4) + 3;
	Atirador* atira = nullptr;
	for (int i = 0; i <= total; i++)
	{
		atira = new Atirador((rand() % 500) + 300, (rand() % 220) + 420);
		atira->SetAlvo(jogador1);
		Gerenciador_Colisoes::getInstance()->Adicionar(atira);
		todasEntis->List_Enti->Add(atira);
		Gerenciador_Colisoes::getInstance()->Adicionar(atira->getProjetil());
		todasEntis->List_Enti->Add(atira->getProjetil());
	}
}

void Fases::Fase1::GerarEspinhos()
{
	int total = rand() % 8 + 3;
	int plata = 0;
	Espinho* espin = nullptr;
	for(int i = 0; i < total; i++)
	{
		plata = rand() % 5;
		switch (plata)
		{
		case 0:
			espin = new Espinho(rand() % 900 + 100, 650);
			Gerenciador_Colisoes::getInstance()->Adicionar(espin);
			todasEntis->List_Enti->Add(espin);
			break;
		case 1:
			espin = new Espinho(rand() % 200 + 90, 580);
			Gerenciador_Colisoes::getInstance()->Adicionar(espin);
			todasEntis->List_Enti->Add(espin);
			break;
		case 2:
			espin = new Espinho(rand() % 50 + 360, 530);
			Gerenciador_Colisoes::getInstance()->Adicionar(espin);
			todasEntis->List_Enti->Add(espin);
			break;
		case 3:
			espin = new Espinho(rand() % 200 + 900, 530);
			Gerenciador_Colisoes::getInstance()->Adicionar(espin);
			todasEntis->List_Enti->Add(espin);
			break;
		case 4:
			espin = new Espinho(rand() % 250 + 560, 580);
			Gerenciador_Colisoes::getInstance()->Adicionar(espin);
			todasEntis->List_Enti->Add(espin);
			break;
		}
	}
}
