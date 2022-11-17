#pragma once
#include "Gerenciador_Grafico.h"
#include "Jogador.h"
#include "Soldado.h"
#include "Gerenciador_Colisoes.h"
#include "Ente.h"
#include "Menu.h"
#include "Atirador.h"
#include "Projetil.h"
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
public:
	bool jogando;
	static Jogo* getInstance();
	int GetNextFreeID();
	void Executar();
};
