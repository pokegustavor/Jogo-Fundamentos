#pragma once
#include "Personagem.h"
#include <time.h>
namespace Entidades
{
	namespace Personagems
	{
		class Jogador : public Personagem
		{
		private:
			bool jogador_um;
			clock_t ultimoDano;
		public:
			Jogador(bool play_um = true);
			~Jogador();
			void executar();
			void receberDano(int valor);
		};
	}
}

