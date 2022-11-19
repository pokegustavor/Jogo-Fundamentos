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
		int deltaX;
		int deltaY;
	public:
		Entidade(int X = 0, int Y = 0);
		~Entidade();
		virtual void executar() = 0;
		virtual void imprimir();
		int getX();
		int getY();
		int getDeltaX();
		int getDeltaY();
		void setX(int X);
		void setY(int Y);
		void setDeltaX(int X);
		void setDeltaY(int Y);
	};
}

