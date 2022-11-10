#include "Jogador.h"
#include <iostream>
Jogador::Jogador(bool play_um):Personagem(50,50)
{
	jogador_um = play_um;
    x = 50;
    y = 50;
    Visual.setSize(sf::Vector2f(20, 20));
    Visual.setFillColor(sf::Color::Red);
}

Jogador::~Jogador()
{
}

void Jogador::executar()
{
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
    {
        x += 2;
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
    {
        x -= 2;
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
    {
        y -= 2;
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
    {
        y += 2;
    }
    Visual.setFillColor(sf::Color::Blue);
    Personagem::executar();
}
