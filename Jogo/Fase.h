#pragma once
#include "Ente.h"
#include "ListaEntidades.h"
#include "Iterador.h"
#include "Jogador.h"
#include "Soldado.h"
using namespace Listas;
class Fase :
	public Ente
{
protected:
	ListaEntidades* todasEntis;
public:
	Fase()
	{
		todasEntis = new ListaEntidades();
		Jogador* joga = new Jogador();
		todasEntis->List_Enti->Add(joga);
		Soldado* solda = new Soldado();
		solda->SetAlvo(joga);
		todasEntis->List_Enti->Add(solda);
	};
	~Fase()
	{
		delete todasEntis;
	};
	void executar()
	{
		Iterador<Entidade>iterator;
		for (iterator = todasEntis->List_Enti->getIterator(); !iterator.isDone(); iterator++)
		{
			Entidade* ente = iterator;
			ente->executar();
		}
	};
	void imprimir()
	{

	};
};

