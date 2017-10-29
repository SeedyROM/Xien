//
// Created by fourtytwo on 10/28/17.
//

#include "Engine.h"
#include "GameState.h"

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

    auto frameRateCap = this->config->settings["display"]["frameRateCap"].as<int>();
    this->window->setFramerateLimit(frameRateCap);
}

void Engine::setState(BaseGameState* state) {
    this->_state = state;
    this->_state->engine = this;
}

BaseGameState* Engine::getState() {
    return this->_state;
}

void Engine::run() {
    sf::Clock clock;

    while (this->window->isOpen()) {
        sf::Time deltaTime = clock.restart();
        sf::Event event;

        while (this->window->pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                this->window->close();
            // Handle the states events.
            if(this->getState()->_handleEvents)
                this->getState()->_handleEvents(event);
        }

        // Calculate for current state.
        if(this->getState()->_update)
            this->getState()->_update(deltaTime.asMilliseconds());

        // Render the state.
        this->window->clear();
        if(this->getState()->_render)
            this->getState()->_render();
        this->window->display();
    }
}
