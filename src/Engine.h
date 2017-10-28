//
// Created by fourtytwo on 10/28/17.
//

#pragma once

#include <memory>
#include <SFML/Graphics.hpp>

namespace xien {
    struct EngineConfig {

        std::unique_ptr<std::string> configFilePath;
    };

    struct Engine {
        Engine();
        ~Engine() = default;

        std::unique_ptr<sf::RenderWindow> window;
        std::unique_ptr<EngineConfig> config;
    };
}

