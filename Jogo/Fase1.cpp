#include "Fase1.h"

Fases::Fase1::Fase1(const bool joga_dois):Fase(joga_dois)
{
	//Posic?o inicial dos jogadores
	jogador1->setX(0);
	jogador1->setY(640);
	if(joga_dois)
	{
		jogador2->setX(40);
		jogador2->setY(640);
	}

	//Adicionar Obstaculos
	GerarPlataformas();
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
		adicionar(solda);
	}
}

void Fases::Fase1::GerarPlataformas()
{
	Plataforma* plata = new Plataforma(0, 660, 2000, 100);
	adicionar(plata);
	plata = new Plataforma(80, 590, 250, 25);
	adicionar(plata);
	plata = new Plataforma(360, 540, 150, 25);
	adicionar(plata);
	plata = new Plataforma(560, 400, 300, 25, true);
	adicionar(plata);
	plata = new Plataforma(0, 440, 490, 25);
	adicionar(plata);
	plata = new Plataforma(910, 440, 450, 25);
	adicionar(plata);
	plata = new Plataforma(900, 540, 250, 25);
	adicionar(plata);
	plata = new Plataforma(560, 590, 300, 25);
	adicionar(plata);
}

void Fases::Fase1::GerarAtiradores()
{
	int total = (rand() % 4) + 3;
	Atirador* atira = nullptr;
	for (int i = 0; i <= total; i++)
	{
		atira = new Atirador((rand() % 500) + 300, (rand() % 220) + 420);
		atira->SetAlvo(jogador1);
		adicionar(atira);
		adicionar(atira->getProjetil());
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
			break;
		case 1:
			espin = new Espinho(rand() % 200 + 90, 580);
			break;
		case 2:
			espin = new Espinho(rand() % 50 + 360, 530);
			break;
		case 3:
			espin = new Espinho(rand() % 200 + 900, 530);
			break;
		case 4:
			espin = new Espinho(rand() % 250 + 560, 580);
			break;
		}
		adicionar(espin);
	}
}
