#pragma once
#include "Entidade.h"
#include "Jogador.h"
using namespace Entidades::Personagems;
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
			Obstaculo(int X, int Y);
			~Obstaculo();
			virtual void Danar(Jogador* alvo);
		};
	}
}
