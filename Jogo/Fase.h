#pragma once
#include "Ente.h"
#include "ListaEntidades.h"
#include "Jogador.h"
#include "Soldado.h"
#include "Gerenciador_Colisoes.h"
#include "Plataforma.h"
using namespace Listas;
using namespace Entidades::Personagems;
using namespace Obstaculos;
class Fase :
	public Ente
{
protected:
	ListaEntidades* todasEntis;
	Jogador* jogador1;
	Jogador* jogador2;
	virtual void GerarSoldados() {};
public:
	Fase(bool dois_joga)
	{
		todasEntis = new ListaEntidades();
		jogador1 = new Jogador(true);
		todasEntis->List_Enti->Add(jogador1);
		if(dois_joga)
		{
			jogador2 = new Jogador(false);
			todasEntis->List_Enti->Add(jogador2);
		}
		else
		{
			jogador2 = nullptr;
		}
		
	};
	~Fase()
	{
		delete todasEntis;
		Gerenciador_Colisoes::getInstance()->Limpar();
	};
	void executar()
	{
		grafico->Janela->clear();
		Iterador<Entidade>iterator;
		for (iterator = todasEntis->List_Enti->getIterator(); !iterator.isDone(); iterator.Next())
		{
			Entidade* ente = iterator;
			ente->executar();
		}
		gerenciar_colisoes();
		imprimir();
	};
	void gerenciar_colisoes()
	{
		Gerenciador_Colisoes::getInstance()->ColidirInimigos(jogador1);
		Gerenciador_Colisoes::getInstance()->ColidirObstaculos(jogador1);
		if(jogador2 != nullptr)
		{
			Gerenciador_Colisoes::getInstance()->ColidirInimigos(jogador2);
			Gerenciador_Colisoes::getInstance()->ColidirObstaculos(jogador2);
		}
	};
	void imprimir()
	{
		grafico->Janela->display();
	};
};

