//
// Created by fourtytwo on 10/28/17.
//

#pragma once

#include <memory>
#include <SFML/Graphics.hpp>
#include "yaml-cpp/yaml.h"

namespace xien {
    struct BaseGameState; // Forward declaration.

    struct EngineConfig {
        EngineConfig();
        ~EngineConfig() = default;

        void load();

        std::unique_ptr<std::string> configFilePath;
        YAML::Node settings;
    };

    struct Engine {
        Engine();
        ~Engine() = default;

        std::unique_ptr<sf::RenderWindow> window;
        std::unique_ptr<EngineConfig> config;

        void setState(BaseGameState* state);
    private:
        BaseGameState* _state;
    };
}

