#pragma once
#include "Ente.h"
#include "Gerenciador_Grafico.h"
namespace Entidades
{
	class Entidade : public Ente
	{
	protected:
		int x;
		int y;
	public:
		Entidade(int X = 0, int Y = 0);
		~Entidade();
		virtual void executar();
		virtual void imprimir();
		int getX();
		int getY();
	};
}

