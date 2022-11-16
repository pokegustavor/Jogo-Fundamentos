#pragma once
#include "Iterator.h"
namespace Listas
{
	template <class TL> class Lista
	{
	private:
		template <class TE> class Elemento
		{
		private:
			TE* pInfo;
		public:
			Elemento<TE>* pProx;
			Elemento(TE*)
			{
				pInfo = TE;
			}
			~Elemento()
			{
				delete pInfo;
			}
			TE* getInfo()
			{
				return pInfo;
			}
		};
		Elemento<TL>* pPrimeiro;
		Elemento<TL>* pUltimo;
		int counter;
	public:
		Lista();
		~Lista();
		void Add(TL* info);
		void Remove(TL* info);
		TL* getItem(int pos);
		TL* getItemByID(int ID);
		const int Count();
		Iterator<TL> getIterator()
		{
			return Iterator<TL>(this);
		}
	};
	template<class TL>
	inline Lista<TL>::Lista()
	{
		pPrimeiro = nullptr;
		pUltimo = nullptr;
		counter = 0;
	}
	template<class TL>
	inline Lista<TL>::~Lista()
	{
		if (pPrimeiro != nullptr)
		{
			Elemento<TL>* atual = pPrimeiro;
			Elemento<TL>* prox;
			while(atual != nullptr)
			{
				prox = atual->pProx;
				delete atual;
				atual = prox;
			}
		}
	}
	template<class TL>
	inline void Lista<TL>::Add(TL* info)
	{
		Elemento<TL>* adiciona = new Elemento<TL>(info);
		if(pPrimeiro == nullptr)
		{
			pPrimeiro = adiciona;
			pUltimo = adiciona;
		}
		else
		{
			pUltimo->pProx = adiciona;
			pUltimo = adiciona;
		}
		counter++;
	}
	template<class TL>
	inline void Lista<TL>::Remove(TL* item)
	{
		Elemento<TL>* temp = pPrimeiro;
		Elemento<TL>* tempant = nullptr;
		while (temp->getInfo() != item)
		{
			if (temp == nullptr)return;
			tempant = temp;
			temp = temp->pProx;
		}
		if (temp == pPrimeiro)
		{
			pPrimeiro = temp->pProx;
		}
		else if (temp == pUltimo)
		{
			tempant->SetProx(nullptr);
			pUltimo = tempant;
		}
		else
		{
			tempant->SetProx(temp->pProx);
		}
		delete temp;
		counter--;
	}
	template<class TL>
	inline TL* Lista<TL>::getItem(int pos)
	{
		Elemento<TL>* temp = pPrimeiro;
		if (temp == nullptr)return nullptr;
		if (pos == 0)
		{
			return temp->getInfo();
		}
		for (int i = 0; i < pos; i++)
		{
			temp = temp->pProx;
			if (temp == nullptr)return nullptr;
		}
		return temp->getInfo();
	}
	template<class TL>
	inline TL* Lista<TL>::getItemByID(int ID)
	{
		Elemento<TL>* temp = pPrimeiro;
		if (temp == nullptr)return nullptr;
		if (ID == temp->getInfo().ID)
		{
			return temp->getInfo();
		}
		while (ID != temp->getInfo().ID)
		{
			temp = temp->pProx;
			if (temp == nullptr)return nullptr;
		}
		return temp->getInfo();
	}
	template<class TL>
	inline const int Lista<TL>::Count()
	{
		return counter;
	}
}

