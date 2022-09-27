#include "State.hpp"

State::State(sf::RenderWindow *window, std::map<std::string, int> *supportesKeys, std::stack<State*> *states) {
    this->window = window;
    this->supportedKeys = supportesKeys;
    this->states = states;
    this->quit = false;
}

State::~State() {}

const bool &State::getQuit() const {
    
    return this->quit;
}

void State::updateMousePositions() {
    
    this->mousePosScreen = sf::Mouse::getPosition();
    this->mousePosWindow = sf::Mouse::getPosition(*this->window);
    this->mousePosView   = this->window->mapPixelToCoords(this->mousePosWindow);
}