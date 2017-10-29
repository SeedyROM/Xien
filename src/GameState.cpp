//
// Created by fourtytwo on 10/28/17.
//

#include "GameState.h"

using namespace xien;
using namespace std::placeholders;

BaseGameState::BaseGameState() {
    this->_init         = std::bind(&BaseGameState::init, this);
    this->_handleEvents = std::bind(&BaseGameState::handleEvents, this, _1);
    this->_update       = std::bind(&BaseGameState::update, this, _1);
    this->_render       = std::bind(&BaseGameState::render, this);
}
