#include <iostream>

#include <SFML/Graphics.hpp>

#include "Engine.h"
#include "GameState.h"

struct TestState : xien::BaseGameState {
    sf::CircleShape x;
    double t;

    TestState() {
        this->x.setPosition(10, 20);
        this->x.setFillColor(sf::Color(255, 0, 127));
        this->x.setRadius(200);

        this->_render = std::bind(&TestState::render, this);
    }

    void render() {
        x.setRadius(abs(static_cast<int>(cos(t) * 50.0f)) + 50.0f);
        x.setPosition(abs(static_cast<int>(cos(t) * 100.0f)), 20.0f);
        engine->window->draw(x);
        t += 0.07;
    }
};

int main()
{
    xien::Engine e;

    TestState s;
    e.setState(&s);

    e.run();

    return 0;
}

