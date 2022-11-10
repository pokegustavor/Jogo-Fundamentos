#pragma once
#include "Entidade.h"
namespace Entidades
{
	namespace Obstaculos
	{
		class Obstaculo : public Entidade
		{
		protected:
			bool Danificavel;
			bool Perigoso;
		public:
			Obstaculo();
			~Obstaculo();
		};
	}
}
