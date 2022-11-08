#pragma once
#include "Base.h"
namespace Entidades
{
	class Entidade : public Base
	{
	protected:
		int x;
		int y;
	public:
		Entidade(int X = 0, int Y = 0);
		~Entidade();
		virtual void executar() = 0;
	};
}

