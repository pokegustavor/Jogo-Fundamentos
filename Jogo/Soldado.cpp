#include "Soldado.h"

Entidades::Personagems::Soldado::Soldado(int X, int Y):Inimigo(X,Y)
{
    Visual.setSize(sf::Vector2f(20.f, 20.f));
    srand(time(NULL));
    grau = (rand() % 2) + 1;
}

Entidades::Personagems::Soldado::~Soldado()
{
}

void Entidades::Personagems::Soldado::executar()
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

void Entidades::Personagems::Soldado::Danar(Jogador* alvo)
{
    alvo->receberDano(grau);
}
