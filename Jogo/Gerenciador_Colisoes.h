#pragma once
class Gerenciador_Colisoes
{
protected:
	static Gerenciador_Colisoes* _instance;
	Gerenciador_Colisoes()
	{
		
	}
	~Gerenciador_Colisoes()
	{
	
	}
public:
	static Gerenciador_Colisoes* getInstance()
	{
		return _instance;
	}
	bool Colidindo(sf::RectangleShape obj1, sf::RectangleShape obj2)
	{
		if (obj1.getPosition().x + obj1.getSize().x <= obj2.getPosition().x)
		{
			return false;
		}
		if (obj1.getPosition().x >= obj2.getPosition().x + obj2.getSize().x)
		{
			return false;
		}
		if (obj1.getPosition().y + obj1.getSize().y <= obj2.getPosition().y)
		{
			return false;
		}
		if (obj1.getPosition().y >= obj2.getPosition().y + obj2.getSize().y)
		{
			return false;
		}
		return true;
	}
};

