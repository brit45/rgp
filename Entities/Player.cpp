#include "Player.hpp"

//--------------------------------------| INITIALISATION FUNCTIONS

void Player::InitVariables() {}

void Player::InitComponents() {

    this->createMovementComponent(100.f, 5.f, 3.f);
}

//--------------------------------------| CONSTRUCTOR & DESTRUCTOR 

Player::Player(float x, float y, sf::Texture &texture) {

    this->InitVariables();
    this->InitComponents();

    this->setTexture(texture);
    this->setPosition(x,y);
}

Player::~Player() {}

//--------------------------------------| FUNCTIONS
