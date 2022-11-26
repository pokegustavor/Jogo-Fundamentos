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
#include <math.h>
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
			atualizarAlvos();
			imprimir();
		};
		void gerenciar_colisoes()
		{
			if (!jogador1->getMorto())
			{
				Gerenciador_Colisoes::getInstance()->ColidirInimigos(jogador1);
				Gerenciador_Colisoes::getInstance()->ColidirObstaculos(jogador1);
				Gerenciador_Colisoes::getInstance()->ColidirProjetils(jogador1);
			}
			if (jogador2 != nullptr && !jogador2->getMorto())
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
			sf::Text text = sf::Text("Vidas 1: " + std::to_string(jogador1->getVidas()), font, 80);
			text.setPosition(sf::Vector2f(20, 20));
			grafico->getJanela()->draw(text);
			if (jogador2 != nullptr)
			{
				text.setString("Vidas 2: " + std::to_string(jogador2->getVidas()));
				text.setPosition(sf::Vector2f(20, 100));
				grafico->getJanela()->draw(text);
			}
			grafico->mostarJanela();
		};
		const bool completa()
		{
			if (jogador1->getMorto() && (jogador2 == nullptr || jogador2->getMorto()))return true;
			return todasEntis->temInimigo();
		}
		void adicionar(Entidade* enti)
		{
			Gerenciador_Colisoes::getInstance()->Adicionar(enti);
			todasEntis->List_Enti->Add(enti);
		}
		void atualizarAlvos()
		{
			Iterador<Entidade>iterator;
			for (iterator = todasEntis->List_Enti->getIterator(); !iterator.isDone(); ++iterator)
			{
				Entidade* ente = iterator;
				Inimigo* ini = dynamic_cast<Inimigo*>(ente);
				if (ini != nullptr && !ini->getMorto())
				{
					if(!jogador1->getMorto() && jogador2 != nullptr && !jogador2->getMorto())
					{
						float distancia1 = sqrt(pow(jogador1->getX() - ini->getX(), 2) + pow(jogador1->getY() - ini->getY(), 2));
						float distancia2 = sqrt(pow(jogador2->getX() - ini->getX(), 2) + pow(jogador2->getY() - ini->getY(), 2));
						if(distancia2 < distancia1)
						{
							ini->SetAlvo(jogador2);
						}
						else
						{
							ini->SetAlvo(jogador1);
						}
					}
					else if(jogador1->getMorto() && jogador2 != nullptr)
					{
						ini->SetAlvo(jogador2);
					}
					else
					{
						ini->SetAlvo(jogador1);
					}
					
				}
			}
		}
	};
}

