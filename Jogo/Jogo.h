#pragma once
#include "Gerenciador_Grafico.h"
#include "Menu.h"
#include "Fase1.h"
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
	static Jogo* getInstance();
	int GetNextFreeID();
	void Executar();
};
