#pragma once
#include "Lista.h"
#include "Entidade.h"
using namespace Entidades;
namespace Listas
{
	class ListaEntidades
	{
	public:
		Lista<Entidade> List_Enti;
		ListaEntidades();
		~ListaEntidades();
	};
}
