#pragma once
#include "Personagem.h"
class Jogador: public Personagem
{
private:
	bool jogador_um;
public:
	Jogador(bool play_um = true);
	~Jogador();
	void executar();
};

