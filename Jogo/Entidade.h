#pragma once
#include "Base.h"
class Entidade : public Base
{
protected:
	int x;
	int y;
public:
	Entidade();
	~Entidade();
	virtual void executar() = 0;
};

