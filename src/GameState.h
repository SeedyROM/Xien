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
        Engine* engine;

        std::function<void()> init;
        std::function<void(const sf::Event)> handleInput;
        std::function<void(const float)> update;
        std::function<void()> render;
    };
}

