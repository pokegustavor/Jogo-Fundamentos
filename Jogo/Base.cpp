#include "Base.h"
Base::Base():Visual(sf::Vector2f(500.0f,500.0f))
{
	id = -1;
}
Base::~Base() {}
const int Base::getID()
{
	return id;
}
