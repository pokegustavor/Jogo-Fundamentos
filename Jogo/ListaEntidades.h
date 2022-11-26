#pragma once
#include "Lista.h"
#include "Entidade.h"
#include "Inimigo.h"
using namespace Entidades;
using namespace Entidades::Personagems;
namespace Listas
{
	class ListaEntidades
	{
	public:
		Lista<Entidade>* List_Enti;
		ListaEntidades()
		{
			List_Enti = new Lista<Entidade>();
		};
		~ListaEntidades()
		{
			delete List_Enti;
		};
		void executar()
		{
			Iterador<Entidade>iterator;
			for (iterator = List_Enti->getIterator(); !iterator.isDone(); ++iterator)
			{
				Entidade* ente = iterator;
				ente->executar();
			}
		}
		bool temInimigo()
		{
			Iterador<Entidade>iterator;
			for (iterator = List_Enti->getIterator(); !iterator.isDone(); ++iterator)
			{
				Entidade* ente = iterator;
				Inimigo* ini = dynamic_cast<Inimigo*>(ente);
				if (ini != nullptr && !ini->getMorto())
				{
					return false;
				}
			}
			return true;
		}
	};
}

