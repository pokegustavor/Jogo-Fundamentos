#pragma once
#include "Gerenciador_Grafico.h"
#include "Jogador.h"
#include "Soldado.h"
#include "Gerenciador_Colisoes.h"
class Jogo
{
private:
	static Jogo* _instance;
	int nextID;
	Jogo();
	~Jogo();
	Jogador* joga;
public:
	static Jogo* getInstance();
	int GetNextFreeID();
	void Executar();
};
