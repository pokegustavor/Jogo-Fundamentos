#include "Fase2.h"

Fases::Fase2::Fase2(bool joga_dois):Fase(joga_dois)
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
	Caixa* cai = new Caixa(40, 600);
	adicionar(cai);

	//Adicionar Inimigos
	Colosso* colo = new Colosso(880, 300);
	colo->SetAlvo(jogador1);
	adicionar(colo);
	Atirador* atira = new Atirador(800, 640);
	atira->SetAlvo(jogador1);
	Gerenciador_Colisoes::getInstance()->Adicionar(atira);
	todasEntis->List_Enti->AddFront(atira);
}

Fases::Fase2::~Fase2()
{
}

void Fases::Fase2::GerarSoldados()
{
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
