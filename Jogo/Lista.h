#pragma once
namespace Listas
{
	template <class T> class Lista
	{
	private:
		template <class E> class Elemento
		{
		private:
			E* pInfo;
		public:
			Elemento<E>* pProx;
			Elemento(E*)
			{
				pInfo = E;
			}
			~Elemento()
			{
				delete pInfo;
			}
			E* getInfo()
			{
				return pInfo;
			}
		};
		Elemento<T>* pPrimeiro;
		Elemento<T>* pUltimo;
		int counter;
	public:
		Lista();
		~Lista();
		void Add(T info);
		const int Count();
	};
	template<class T>
	inline Lista<T>::Lista()
	{
		pPrimeiro = nullptr;
		pUltimo = nullptr;
		counter = 0;
	}
	template<class T>
	inline Lista<T>::~Lista()
	{
		if (pPrimeiro != nullptr)
		{
			Elemento<T>* atual = pPrimeiro;
			Elemento<T>* prox;
			while(atual != nullptr)
			{
				prox = atual->pProx;
				delete atual;
				atual = prox;
			}
		}
	}
	template<class T>
	inline void Lista<T>::Add(T info)
	{
		Elemento<T>* adiciona = new Elemento<T>(info);
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
	template<class T>
	inline const int Lista<T>::Count()
	{
		return counter;
	}
}

