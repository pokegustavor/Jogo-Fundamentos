#include "Fase2.h"

Fases::Fase2::Fase2(bool joga_dois) :Fase(joga_dois)
{
	//Posicão inicial dos jogadores
	jogador1->setX(0);
	jogador1->setY(640);
	if (joga_dois)
	{
		jogador2->setX(40);
		jogador2->setY(640);
	}

	//Adicionar Obstaculos
	GerarPlataformas();
	GerarCaixas();

	//Adicionar Inimigos
	GerarSoldados();
	GerarColossos();
}

Fases::Fase2::~Fase2()
{
}

void Fases::Fase2::GerarSoldados()
{
	int total = (rand() % 7) + 3;
	Soldado* solda = nullptr;
	for (int i = 0; i <= total; i++)
	{
		solda = new Soldado((rand() % 600) + 300, (rand() % 220) + 420);
		solda->SetAlvo(jogador1);
		adicionar(solda);
	}
}

void Fases::Fase2::GerarPlataformas()
{
	Plataforma* plata = new Plataforma(0, 660, 2000, 100);
	adicionar(plata);
	plata = new Plataforma(80, 590, 450, 25);
	adicionar(plata);
	plata = new Plataforma(550, 520, 250, 25);
	adicionar(plata);
	plata = new Plataforma(820, 590, 350, 25);
	adicionar(plata);
	plata = new Plataforma(0, 450, 520, 25);
	adicionar(plata);
	plata = new Plataforma(550, 380, 250, 25);
	adicionar(plata);
	plata = new Plataforma(830, 450, 520, 25);
	adicionar(plata);
	plata = new Plataforma(30, 310, 600, 25);
	adicionar(plata);
	plata = new Plataforma(660, 250, 120, 25);
	adicionar(plata);
	plata = new Plataforma(830, 180, 600, 25);
	adicionar(plata);
}

void Fases::Fase2::GerarColossos()
{
	int total = (rand() % 3) + 3;
	Colosso* colo = nullptr;
	for (int i = 0; i <= total; i++)
	{
		colo = new Colosso((rand() % 600) + 680, (rand() % 640));
		colo->SetAlvo(jogador1);
		adicionar(colo);
	}
}

void Fases::Fase2::GerarCaixas()
{
	int total = (rand() % 9) + 8;
	int plata = 0;
	Caixa* caixa = nullptr;
	for (int i = 0; i < total; i++)
	{
		plata = rand() % 8;
		switch (plata)
		{
		case 0:
			caixa = new Caixa((rand() % 450) + 80, 530);
			break;
		case 1:
			caixa = new Caixa((rand() % 250) + 550,460);
			break;
		case 2:
			caixa = new Caixa((rand() % 350) + 820, 530);
			break;
		case 3:
			caixa = new Caixa((rand() % 520), 390);
			break;
		case 4:
			caixa = new Caixa((rand() % 250) + 550, 320);
			break;
		case 5:
			caixa = new Caixa((rand() % 520) + 830, 340);
			break;
		case 6:
			caixa = new Caixa((rand() % 600) + 30, 250);
			break;
		case 7:
			caixa = new Caixa((rand() % 600) + 830, 120);
			break;
		}
		adicionar(caixa);
	}
}
