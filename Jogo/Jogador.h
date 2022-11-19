#pragma once
#include "Personagem.h"
namespace Entidades
{
	namespace Personagems
	{
		class Jogador : public Personagem
		{
		private:
			bool jogador_um;
			bool noChao;
		public:
			Jogador(bool play_um = true);
			~Jogador();
			void executar();
			void setChao(bool chao);
		};
	}
}

