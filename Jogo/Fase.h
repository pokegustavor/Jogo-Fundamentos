#pragma once
#include "Ente.h"
#include "ListaEntidades.h"
#include "Jogador.h"
#include "Soldado.h"
#include "Gerenciador_Colisoes.h"
#include "Plataforma.h"
#include "Atirador.h"
#include "Espinho.h"
#include "Colosso.h"
#include "Caixa.h"
using namespace Listas;
using namespace Entidades::Personagems;
using namespace Obstaculos;
namespace Fases
{
	class Fase :
		public Ente
	{
	protected:
		ListaEntidades* todasEntis;
		Jogador* jogador1;
		Jogador* jogador2;
		virtual void GerarSoldados() = 0;
		virtual void GerarPlataformas() = 0;
	public:
		Fase(bool dois_joga)
		{
			todasEntis = new ListaEntidades();
			jogador1 = new Jogador(true);
			todasEntis->List_Enti->Add(jogador1);
			if (dois_joga)
			{
				jogador2 = new Jogador(false);
				todasEntis->List_Enti->Add(jogador2);
			}
			else
			{
				jogador2 = nullptr;
			}
		};
		~Fase()
		{
			delete todasEntis;
			Gerenciador_Colisoes::getInstance()->Limpar();
		};
		void executar()
		{
			grafico->getJanela()->clear();
			todasEntis->executar();
			gerenciar_colisoes();
			imprimir();
		};
		void gerenciar_colisoes()
		{
			Gerenciador_Colisoes::getInstance()->ColidirInimigos(jogador1);
			Gerenciador_Colisoes::getInstance()->ColidirObstaculos(jogador1);
			Gerenciador_Colisoes::getInstance()->ColidirProjetils(jogador1);
			if (jogador2 != nullptr)
			{
				Gerenciador_Colisoes::getInstance()->ColidirInimigos(jogador2);
				Gerenciador_Colisoes::getInstance()->ColidirObstaculos(jogador2);
				Gerenciador_Colisoes::getInstance()->ColidirProjetils(jogador2);
			}
			Iterador<Entidade>iterator;
			for (iterator = todasEntis->List_Enti->getIterator(); !iterator.isDone(); ++iterator)
			{
				Entidade* ente = iterator;
				Inimigo* ini = dynamic_cast<Inimigo*>(ente);
				if (ini != nullptr && !ini->getMorto())
				{
					Gerenciador_Colisoes::getInstance()->ColidirObstaculos(ini);
					Gerenciador_Colisoes::getInstance()->ColidirInimigos(ini);
				}
			}
		};
		void imprimir()
		{
			sf::Font font;
			font.loadFromFile("arial.ttf");
			sf::Text text = sf::Text("Vidas: " + std::to_string(jogador1->getVidas()), font, 80);
			text.setPosition(sf::Vector2f(20, 20));
			grafico->getJanela()->draw(text);
			grafico->getJanela()->display();
		};
		const bool completa()
		{
			if (jogador1->getMorto())return true;
			return todasEntis->temInimigo();
		}
		void adicionar(Entidade* enti)
		{
			Gerenciador_Colisoes::getInstance()->Adicionar(enti);
			todasEntis->List_Enti->Add(enti);
		}
	};
}

