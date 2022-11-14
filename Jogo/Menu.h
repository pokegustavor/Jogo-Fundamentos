#pragma once
#include "Ente.h"
#include "SFML/Graphics.hpp"
class Menu :
    public Ente
{
private:
    int Menu_Atual;
    bool graf_iniciado;
public:
    Menu()
    {
        Menu_Atual = 0;
        graf_iniciado = false;
    }
    ~Menu()
    {
        
    }
    void executar() 
    {
        if(!graf_iniciado)
        {
            grafico->Iniciar();
            graf_iniciado = true;
        }
        imprimir();
    };
    void imprimir() {};
    sf::RenderWindow* getJanela() { return grafico->Janela; }
};

