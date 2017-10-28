#include <iostream>
#include <memory>
#include <algorithm>
#include <fstream>

#include <SFML/Graphics.hpp>
#include "selene.h"
#include "Engine.h"


int main()
{
    auto e = std::make_unique<xien::Engine>();

    while (e->window->isOpen()) {
        sf::Event event;
        while (e->window->pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                e->window->close();
        }

        e->window->clear();
        e->window->display();
    }

    return 0;
}

