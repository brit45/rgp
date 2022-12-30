#include "Player.hpp"

//--------------------------------------| INITIALISATION FUNCTIONS

void Player::InitVariables() {}

void Player::InitComponents() {

    
}

//--------------------------------------| CONSTRUCTOR & DESTRUCTOR 

Player::Player(float x, float y, sf::Texture &texture_sheet) {

    this->InitVariables();
    this->InitComponents();
    this->setPosition(x,y);
    
    this->createMovementComponent(100.f, 5.f, 3.f);
    this->createAnimationComponent(texture_sheet);

    this->animationComponent->addAnimation("IDLE_BOTTOM", 5.0f, 0, 0, 7, 0, 60, 60);
    this->animationComponent->addAnimation("IDLE_LEFT",   5.0f, 0, 1, 7, 1, 60, 60);
    this->animationComponent->addAnimation("IDLE_RIGHT",  5.0f, 0, 2, 7, 2, 60, 60);
    this->animationComponent->addAnimation("IDLE_TOP",    5.0f, 0, 3, 7, 3, 60, 60);
}

Player::~Player() {}

void Player::update(const float &dt) {

    this->movementComponent->update(dt);

    this->animationComponent->play("IDLE_LEFT", dt);
}

//--------------------------------------| FUNCTIONS
