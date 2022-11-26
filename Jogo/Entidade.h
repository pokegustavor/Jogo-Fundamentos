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
		Entidade(const int X = 0, const int Y = 0);
		~Entidade();
		virtual void executar() = 0;
		virtual void imprimir();
		const int getX();
		const int getY();
		const int getDeltaX();
		const int getDeltaY();
		void setX(const int X);
		void setY(const int Y);
		void setDeltaX(const int X);
		void setDeltaY(const int Y);
	};
}

