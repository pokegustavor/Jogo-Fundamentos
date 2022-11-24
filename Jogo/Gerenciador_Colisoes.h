#pragma once
#include "Inimigo.h"
#include "Obstaculo.h"
#include "Jogador.h"
#include "Entidade.h"
#include "Plataforma.h"
#include "Projetil.h"
#include <list>
using namespace std;
using namespace Entidades::Personagems;
using namespace Entidades::Obstaculos;
using namespace Entidades;
using namespace Listas;
class Gerenciador_Colisoes
{
private:
	vector<Inimigo*> LIs;
	list<Obstaculo*> LOs;
	list<Projetil*> PRs;
	static Gerenciador_Colisoes* _instance;
	Gerenciador_Colisoes() :LIs(), LOs(), PRs()
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
		vector<Inimigo*>::iterator iterador;
		sf::RectangleShape futuro = sf::RectangleShape(sf::Vector2f(persona->Visual.getSize().x, persona->Visual.getSize().y));
		for (iterador = LIs.begin(); iterador != LIs.end(); ++iterador)
		{
			if ((*iterador)->getMorto())continue;
			futuro.setPosition(sf::Vector2f(persona->getX() + persona->getDeltaX(), persona->getY() + persona->getDeltaY()));
			if (Colidindo(futuro, (*iterador)->Visual))//Verifica se existe uma colisão entre a posição futura e o objeto
			{
				futuro.setPosition(sf::Vector2f(futuro.getPosition().x, futuro.getPosition().y - persona->getDeltaY()));//Desfaz o movimento Y
				if (Colidindo(futuro, (*iterador)->Visual))//Verifica se ainda esta colidindo pelas laterais
				{
					(*iterador)->Danar(persona);
					persona->setDeltaX(-persona->getDeltaX());
					futuro.setPosition(sf::Vector2f(persona->getX(), futuro.getPosition().y));

				}
				futuro.setPosition(sf::Vector2f(futuro.getPosition().x - persona->getDeltaX(), futuro.getPosition().y + persona->getDeltaY()));//Desfaz o movimento X e refaz o movimento Y
				if (Colidindo(futuro, (*iterador)->Visual))//Verifica se ainda esta colidindo pelas verticais
				{
					persona->setDeltaY(-persona->getDeltaY());
					if (persona->getDeltaY() > 0) //Se o jogador esta se movendo para baixo
					{
						(*iterador)->Danar(persona);
					}
					else if (persona->getDeltaY() < 0) //Se o jogador esta se movendo para cima
					{
						(*iterador)->receberDano(1);
						persona->setDeltaY(-16);
					}
				}
			}
		}
	}
	void ColidirObstaculos(Jogador* persona)
	{
		list<Obstaculo*>::iterator iterador;
		sf::RectangleShape futuro = sf::RectangleShape(sf::Vector2f(persona->Visual.getSize().x, persona->Visual.getSize().y));
		for (iterador = LOs.begin(); iterador != LOs.end(); ++iterador)
		{
			futuro.setPosition(sf::Vector2f(persona->getX() + persona->getDeltaX(), persona->getY() + persona->getDeltaY()));
			if (Colidindo(futuro, (*iterador)->Visual))//Verifica se existe uma colisão entre a posição futura e o objeto
			{
				(*iterador)->Danar(persona);
				int extra = 0;
				Plataforma* plata = dynamic_cast<Plataforma*>((*iterador));
				if (plata != nullptr && plata->getMovel() && plata->getSubindo())
				{
					extra = 2;
				}
				futuro.setPosition(sf::Vector2f(futuro.getPosition().x, futuro.getPosition().y - persona->getDeltaY() - extra));//Desfaz o movimento Y
				if (Colidindo(futuro, (*iterador)->Visual))//Verifica se ainda esta colidindo pelas laterais
				{
					if (persona->getDeltaX() > 0) //Se o jogador esta se movendo para direita
					{
						persona->setX((*iterador)->getX() - persona->Visual.getSize().x);
						persona->setDeltaX(0);
						futuro.setPosition(sf::Vector2f(persona->getX(), futuro.getPosition().y));
					}
					else if (persona->getDeltaX() < 0) //Se o jogador esta se movendo para esquerda
					{
						persona->setX((*iterador)->getX() + (*iterador)->Visual.getSize().x);
						persona->setDeltaX(0);
						futuro.setPosition(sf::Vector2f(persona->getX(), futuro.getPosition().y));
					}
				}
				futuro.setPosition(sf::Vector2f(futuro.getPosition().x - persona->getDeltaX(), futuro.getPosition().y + persona->getDeltaY()));//Desfaz o movimento X e refaz o movimento Y
				if (Colidindo(futuro, (*iterador)->Visual))//Verifica se ainda esta colidindo pelas verticais
				{
					if (persona->getDeltaY() > 0) //Se o jogador esta se movendo para baixo
					{
						persona->setY((*iterador)->getY() - persona->Visual.getSize().y);
						persona->setDeltaY(0);
						persona->setChao(true);
					}
					else if (persona->getDeltaY() < 0) //Se o jogador esta se movendo para cima
					{
						persona->setY((*iterador)->getY() + (*iterador)->Visual.getSize().y);
						persona->setDeltaY(0);
					}
				}
			}
		}
	}
	void ColidirObstaculos(Inimigo* inimi)
	{
		list<Obstaculo*>::iterator iterador;
		sf::RectangleShape futuro = sf::RectangleShape(sf::Vector2f(inimi->Visual.getSize().x, inimi->Visual.getSize().y));
		for (iterador = LOs.begin(); iterador != LOs.end(); ++iterador)
		{
			futuro.setPosition(sf::Vector2f(inimi->getX() + inimi->getDeltaX(), inimi->getY() + inimi->getDeltaY()));
			if (Colidindo(futuro, (*iterador)->Visual))//Verifica se existe uma colisão entre a posição futura e o objeto
			{
				futuro.setPosition(sf::Vector2f(futuro.getPosition().x, futuro.getPosition().y - inimi->getDeltaY()));//Desfaz o movimento Y
				if (Colidindo(futuro, (*iterador)->Visual))//Verifica se ainda esta colidindo pelas laterais
				{
					if (inimi->getDeltaX() > 0) //Se o jogador esta se movendo para direita
					{
						inimi->setX((*iterador)->getX() - inimi->Visual.getSize().x);
						inimi->setDeltaX(0);
						futuro.setPosition(sf::Vector2f(inimi->getX(), futuro.getPosition().y));
					}
					else if (inimi->getDeltaX() < 0) //Se o jogador esta se movendo para esquerda
					{
						inimi->setX((*iterador)->getX() + (*iterador)->Visual.getSize().x);
						inimi->setDeltaX(0);
						futuro.setPosition(sf::Vector2f(inimi->getX(), futuro.getPosition().y));
					}
				}
				futuro.setPosition(sf::Vector2f(futuro.getPosition().x - inimi->getDeltaX(), futuro.getPosition().y + inimi->getDeltaY()));//Desfaz o movimento X e refaz o movimento Y
				if (Colidindo(futuro, (*iterador)->Visual))//Verifica se ainda esta colidindo pelas verticais
				{
					if (inimi->getDeltaY() > 0) //Se o jogador esta se movendo para baixo
					{
						inimi->setY((*iterador)->getY() - inimi->Visual.getSize().y);
						inimi->setDeltaY(0);
						inimi->setChao(true);
					}
					else if (inimi->getDeltaY() < 0) //Se o jogador esta se movendo para cima
					{
						inimi->setY((*iterador)->getY() + (*iterador)->Visual.getSize().y);
						inimi->setDeltaY(0);
					}
				}
			}
		}
	}
	void ColidirProjetils(Jogador* persona)
	{
		list<Projetil*>::iterator iterator;
		for(iterator = PRs.begin(); iterator != PRs.end(); ++iterator)
		{
			Projetil* proj = *iterator;
			if(!proj->getInativo() && Colidindo(persona->Visual,proj->Visual))
			{
				persona->receberDano(1);
				proj->setInativo(true);
			}
		}
	}
	void Adicionar(Entidade* enti)
	{
		Obstaculo* obst = dynamic_cast<Obstaculo*>(enti);
		Inimigo* ini = dynamic_cast<Inimigo*>(enti);
		Projetil* proj = dynamic_cast<Projetil*>(enti);
		if (obst != nullptr)
		{
			LOs.push_back(obst);
		}
		else if (ini != nullptr)
		{
			LIs.push_back(ini);
		}
		else if (proj != nullptr)
		{
			PRs.push_back(proj);
		}
	}
	void Limpar()
	{
		LOs.clear();
		LIs.clear();
		PRs.clear();
	}
};

