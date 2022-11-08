#include "Base.h"
class Base
{
protected:
	int id;
public:
	Base() {}
	~Base() {}
	virtual void executar() = 0;
	virtual void imprimir() = 0;
	const int getID()
	{
		return id;
	}
};
