#include "Jogo.h"
#include "SFML/Graphics.hpp"

Jogo* Jogo::_instance = new Jogo();
Gerenciador_Grafico* Gerenciador_Grafico::_instance = new Gerenciador_Grafico();
Gerenciador_Colisoes* Gerenciador_Colisoes::_instance = new Gerenciador_Colisoes();
int main()
{
    Gerenciador_Grafico::getInstance()->Iniciar();
    Jogo::getInstance()->Executar();
    return 0;
}

Jogo::Jogo()
{
    nextID = 0;
    joga = new Jogador();
    
}
Jogo::~Jogo()
{
}
Jogo* Jogo::getInstance()
{
    return _instance;
}

int Jogo::GetNextFreeID()
{
    nextID++;
    return nextID - 1;
}

void Jogo::Executar()
{
    sf::RenderWindow* Janela = Gerenciador_Grafico::getInstance()->Janela;
    sf::RectangleShape shape(sf::Vector2f(2000.f, 100.f));
    shape.setFillColor(sf::Color::Green);
    shape.setPosition(sf::Vector2f(0.f, 400.f));
    Soldado* solda = new Soldado();
    solda->SetAlvo(joga);
    while (Janela->isOpen())
    {
        sf::Event event;
        while (Janela->pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                Janela->close();
        }

        Janela->clear();
        Janela->draw(shape);
        joga->executar();
        solda->executar();
        Janela->display();
        if (Gerenciador_Colisoes::getInstance()->Colidindo(joga->Visual, solda->Visual))
        {
            Janela->close();
        }
    }
}
