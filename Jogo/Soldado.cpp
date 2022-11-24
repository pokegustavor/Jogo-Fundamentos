#include "Soldado.h"

Entidades::Personagems::Soldado::Soldado(int X, int Y):Inimigo(X,Y)
{
    Visual.setSize(sf::Vector2f(20.f, 20.f));
    grau = (rand() % 2) + 1;
}

Entidades::Personagems::Soldado::~Soldado()
{
}

void Entidades::Personagems::Soldado::executar()
{
    if (morto)return;
    Visual.setFillColor(sf::Color::Red);
    Personagem::executar();
    if (deltaX > 0)deltaX--;
    if (deltaX < 0)deltaX++;
    if (deltaY > 0)deltaY--;
    if (deltaY < 0)deltaY++;
    if(Alvo != nullptr)
    {
        if(Alvo->getX() < x)
        {
            deltaX -= 1;
        }
        if (Alvo->getX() > x)
        {
            deltaX += 1;
        }
        if (Alvo->getY() < y && noChao)
        {
            deltaY -= 18;
        }
    }
    if (!noChao && deltaY <= 3)
    {
        deltaY += 2;
    }
    noChao = false;
    if (deltaX > 4)deltaX = 4;
    if (deltaX < -4)deltaX = -4;
    
}

void Entidades::Personagems::Soldado::Danar(Jogador* alvo)
{
    alvo->receberDano(grau);
}
