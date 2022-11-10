#include "Soldado.h"

Soldado::Soldado():Inimigo(80,80)
{
    Visual.setSize(sf::Vector2f(20.f, 20.f));
}

Soldado::~Soldado()
{
}

void Soldado::executar()
{
    Visual.setFillColor(sf::Color::Red);
    if(Alvo != nullptr)
    {
        if(Alvo->getX() < x)
        {
            x -= 1;
        }
        if (Alvo->getX() > x)
        {
            x += 1;
        }
        if (Alvo->getY() < y)
        {
            y -= 1;
        }
        if (Alvo->getY() > y)
        {
            y += 1;
        }
    }
    Personagem::executar();
}
