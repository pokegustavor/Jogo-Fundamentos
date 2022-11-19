#pragma once
#include "Inimigo.h"
#include "Obstaculo.h"
#include "Jogador.h"
#include "Entidade.h"
#include <list>
using namespace std;
using namespace Entidades::Personagems;
using namespace Entidades::Obstaculos;
using namespace Entidades;
class Gerenciador_Colisoes
{
private:
	vector<Inimigo*> LIs;
	list<Obstaculo*> LOs;
	static Gerenciador_Colisoes* _instance;
	Gerenciador_Colisoes():LIs(),LOs()
	{
	}
	~Gerenciador_Colisoes()
	{
	
	}
public:
	static Gerenciador_Colisoes* getInstance()
	{
		return _instance;
	}
	bool Colidindo(sf::RectangleShape obj1, sf::RectangleShape obj2)
	{
		if (obj1.getPosition().x + obj1.getSize().x <= obj2.getPosition().x)
		{
			return false;
		}
		if (obj1.getPosition().x >= obj2.getPosition().x + obj2.getSize().x)
		{
			return false;
		}
		if (obj1.getPosition().y + obj1.getSize().y <= obj2.getPosition().y)
		{
			return false;
		}
		if (obj1.getPosition().y >= obj2.getPosition().y + obj2.getSize().y)
		{
			return false;
		}
		return true;
	}
	void ColidirInimigos(Jogador* persona)
	{
	
	}
	void ColidirObstaculos(Jogador* persona)
	{
		list<Obstaculo*>::iterator iterador;
		sf::RectangleShape futuro = sf::RectangleShape(sf::Vector2f(persona->Visual.getSize().x, persona->Visual.getSize().y));
		for(iterador = LOs.begin();iterador != LOs.end();++iterador)
		{
			futuro.setPosition(sf::Vector2f(persona->getX() + persona->getDeltaX(), persona->getY() + persona->getDeltaY()));
			if(Colidindo(futuro, (*iterador)->Visual))//Verifica se existe uma colisão entre a posição futura e o objeto
			{
				(*iterador)->Danar(persona);
				futuro.setPosition(sf::Vector2f(futuro.getPosition().x, futuro.getPosition().y - persona->getDeltaY()));//Desfaz o movimento Y
				if(Colidindo(futuro, (*iterador)->Visual))//Verifica se ainda esta colidindo pelas laterais
				{
					if(persona->getDeltaX() > 0) //Se o jogador esta se movendo para direita
					{
						persona->setX((*iterador)->getX() - persona->Visual.getSize().x);
						persona->setDeltaX(0);
						futuro.setPosition(sf::Vector2f(persona->getX(), futuro.getPosition().y));
					}
					else if (persona->getDeltaX() < 0) //Se o jogador esta se movendo para esquerda
					{
						persona->setX((*iterador)->getX() + (*iterador)->Visual.getSize().x );
						persona->setDeltaX(0);
						futuro.setPosition(sf::Vector2f(persona->getX(), futuro.getPosition().y));
					}
				}
				futuro.setPosition(sf::Vector2f(futuro.getPosition().x - persona->getDeltaX(), futuro.getPosition().y + persona->getDeltaY()));//Desfaz o movimento X e refaz o movimento Y
				if (Colidindo(futuro, (*iterador)->Visual))//Verifica se ainda esta colidindo pelas verticais
				{
					if (persona->getDeltaY() > 0) //Se o jogador esta se movendo para baixo
					{
						persona->setY((*iterador)->getY() - persona->Visual.getSize().y );
						persona->setDeltaY(0);
						persona->setChao(true);
					}
					else if (persona->getDeltaY() < 0) //Se o jogador esta se movendo para cima
					{
						persona->setY((*iterador)->getY() + (*iterador)->Visual.getSize().y );
						persona->setDeltaY(0);
					}
				}
			}
		}
	}
	void Adicionar(Entidade* enti)
	{
		Obstaculo* obst = static_cast<Obstaculo*>(enti);
		if(obst !=nullptr)
		{
			LOs.push_back(obst);
		}
		else
		{
			Inimigo* ini = static_cast<Inimigo*>(enti);
			if(ini != nullptr)
			{
				LIs.push_back(ini);
			}
		}
	}
	void Limpar()
	{
		LOs.clear();
		LIs.clear();
	}
};

