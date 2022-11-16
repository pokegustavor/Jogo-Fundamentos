#pragma once
#include "Lista.h"
#include "Entidade.h"
using namespace Entidades;
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
	};
}

