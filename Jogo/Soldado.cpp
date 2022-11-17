#include "Soldado.h"

Soldado::Soldado(int X, int Y):Inimigo(X,Y)
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
