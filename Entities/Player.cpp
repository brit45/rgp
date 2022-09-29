#include "Player.hpp"

//--------------------------------------| INITIALISATION FUNCTIONS

void Player::InitVariables() {}

void Player::InitComponents() {}

//--------------------------------------| CONSTRUCTOR & DESTRUCTOR 

Player::Player(float x, float y, sf::Texture *texture) {

    this->InitVariables();
    this->InitComponents();

    this->createSprite(texture);
    this->setPosition(x,y);
}

Player::~Player() {}

//--------------------------------------| FUNCTIONS
