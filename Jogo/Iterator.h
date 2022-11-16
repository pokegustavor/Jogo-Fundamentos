#pragma once
#include "Lista.h"
namespace Listas
{
	template<class Tem>class Iterator
	{
	private:
		long _atual;
		Lista<Tem>* _lista;
	public:
		Iterator()
		{
			_atual = 0;
			_lista = nullptr;
		};
		Iterator(Lista<Tem>* lista)
		{
			_atual = 0;
			_lista = lista;
		};
		~Iterator() {};
		void Begin()
		{
			_atual = 0;
		};
		void operator ++()
		{
			_atual++;
		};
		operator Tem*() 
		{
			if (!isDone)
			{
				return _lista->getItem(_atual);
			}
			else
			{
				return nullptr;
			}
		}
		const bool isDone()
		{
			return _atual < _lista->Count();
		}
	};
}
