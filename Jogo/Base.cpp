#include "Base.h"
Base::Base():Visual(sf::Vector2f(20.0f,20.0f))
{
	id = -1;
}
Base::~Base() {}
const int Base::getID()
{
	return id;
}
