#include "Jogador.h"
#include <iostream>
Entidades::Personagems::Jogador::Jogador(bool play_um):Personagem(50,50)
{
    vida = 10;
	jogador_um = play_um;
    Visual.setSize(sf::Vector2f(20, 20));
    Visual.setFillColor(sf::Color::Red);
    noChao = false;
    ultimoDano = clock_t();
}

Entidades::Personagems::Jogador::~Jogador()
{
}

void Entidades::Personagems::Jogador::executar()
{
    Visual.setFillColor(sf::Color::Blue);
    Personagem::executar();
    if (deltaX > 0)deltaX--;
    if (deltaX < 0)deltaX++;
    if (deltaY > 0)deltaY--;
    if (deltaY < 0)deltaY++;
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
    {
        deltaX += 2;
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
    {
        deltaX -= 2;
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::W) && noChao)
    {
        deltaY -= 22; //Negativo para cima
    }
    if (!noChao && deltaY <= 3)
    {
        deltaY+=2;
    }
    noChao = false;
    if (deltaX > 4)deltaX = 4;
    if (deltaX < -4)deltaX = -4;
}

void Entidades::Personagems::Jogador::receberDano(int valor)
{
    clock_t now = clock();
    if (float(now - ultimoDano) / CLOCKS_PER_SEC < 1)return;
    vida -= valor;
    ultimoDano = now;
}

