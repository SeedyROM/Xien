#include <iostream>

#include <SFML/Graphics.hpp>
#include <GameState.h>

#include "Engine.h"

struct TestState : xien::BaseGameState {
    sf::CircleShape x;
    double t;

    TestState() {
        this->x.setPosition(10, 20);
        this->x.setFillColor(sf::Color(255, 0, 127));
        this->x.setRadius(200);

        this->render = [this]() {
            x.setRadius(abs(cos(t) * 50) + 50);
            engine->window->draw(x);
            t += 0.02;
        };
    }
};

int main()
{
    xien::Engine e;

    TestState s;
    e.setState(&s);

    while (e.window->isOpen()) {
        sf::Event event;
        while (e.window->pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                e.window->close();
        }

        e.window->clear();
        s.render();
        e.window->display();
    }

    return 0;
}

