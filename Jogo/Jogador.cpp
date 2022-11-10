#include "Jogador.h"
#include <iostream>
Jogador::Jogador(bool play_um):Personagem(50,50)
{
	jogador_um = play_um;
    Visual.setFillColor(sf::Color::Cyan);
    x = 50;
    y = 50;
    Visual.setSize(sf::Vector2f(500, 500));
}

Jogador::~Jogador()
{
}

void Jogador::executar()
{
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
    {
        Visual.setPosition(sf::Vector2f(Visual.getPosition().x + .1f, Visual.getPosition().y));
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
    {
        Visual.setPosition(sf::Vector2f(Visual.getPosition().x - .1f, Visual.getPosition().y));
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
    {
        Visual.setPosition(sf::Vector2f(Visual.getPosition().x, Visual.getPosition().y + .1f));
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
    {
        Visual.setPosition(sf::Vector2f(Visual.getPosition().x, Visual.getPosition().y - .1f));
    }
    Entidade::executar();
    imprimir();
    std::cout << x << ", " << y << "\n";
}
