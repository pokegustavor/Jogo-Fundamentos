#pragma once
#include "Gerenciador_Grafico.h"
#include "Jogador.h"
#include "Soldado.h"
#include "Gerenciador_Colisoes.h"
#include "Ente.h"
#include "Menu.h"
#include "Fase.h"
class Jogo
{
private:
	static Jogo* _instance;
	int nextID;
	Jogo();
	~Jogo();
	Jogador* joga;
	Menu* menu;
	Fase* fase;
public:
	static Jogo* getInstance();
	int GetNextFreeID();
	void Executar();
};
