//
// Created by fourtytwo on 10/28/17.
//

#include "Engine.h"
#include "GameState.h"

#include <iostream>
#include <boost/filesystem.hpp>

using namespace xien;

EngineConfig::EngineConfig() {
    auto currentPath = boost::filesystem::initial_path();
    currentPath.append("../test_files/config.yml");

    this->configFilePath = std::make_unique<std::string>(currentPath.string());
}

void EngineConfig::load() {
    this->settings = YAML::LoadFile(this->configFilePath->c_str());
}

Engine::Engine() {
    this->config = std::make_unique<EngineConfig>();
    this->window = std::make_unique<sf::RenderWindow>();

    this->config->load();
    
    auto width = this->config->settings["display"]["width"].as<int>();
    auto height = this->config->settings["display"]["height"].as<int>();
    
    this->window->create(sf::VideoMode(width, height), "Xien Engine");

    auto framerate_cap = this->config->settings["display"]["framerate_cap"].as<int>();
    this->window->setFramerateLimit(framerate_cap);
}

void Engine::setState(BaseGameState* state) {
    this->_state = state;
    this->_state->engine = this;
}
