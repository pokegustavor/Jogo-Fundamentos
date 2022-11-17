#pragma once
#include "Lista.h"
namespace Listas
{
	template<class Tem>class Iterador
	{
	private:
		long _atual;
		Lista<Tem>* _lista;
	public:
		Iterador()
		{
			_atual = 0;
			_lista = nullptr;
		};
		Iterador(Lista<Tem>* lista)
		{
			_atual = 0;
			_lista = lista;
		};
		~Iterador() {};
		void Begin()
		{
			_atual = 0;
		};
		Iterador<Tem> operator++()
		{
			Iterador<Tem> temp = *this;
			_atual++;
			return temp;
		};
		void Next()
		{
			_atual++;
		}
		operator Tem* ()
		{
			if (_lista != nullptr && !isDone)
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

