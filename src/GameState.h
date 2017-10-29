//
// Created by fourtytwo on 10/28/17.
//

#pragma once

#include <algorithm>
#include <functional>
#include <memory>
#include <iostream>
#include <SFML/Graphics.hpp>

namespace xien {
    struct Engine; // Forward declaration.
    struct BaseGameState {
        BaseGameState();

        virtual void init() {}
        virtual void handleEvents(const sf::Event) {}
        virtual void update(const float) {}
        virtual void render() {}

        Engine* engine;
        std::function<void()> _init;
        std::function<void(const sf::Event)> _handleEvents;
        std::function<void(const float)> _update;
        std::function<void()> _render;
    };
}

