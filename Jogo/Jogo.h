#pragma once
#include "Gerenciador_Grafico.h"
#include "Menu.h"
#include "Fase1.h"
#include "Fase2.h"
using namespace Gerenciadores;
using namespace Fases;
class Jogo
{
private:
	static Jogo* _instance;
	int nextID;
	Jogo();
	~Jogo();
	Menu* menu;
	Fase* fase;
public:
	bool jogando;
	int level;
	static Jogo* getInstance();
	int GetNextFreeID();
	void Executar();
	Fase* getFase();
};
