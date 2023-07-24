#include "Player.hpp"

//--------------------------------------| INITIALISATION FUNCTIONS

void Player::InitVariables() {

    this->attacking = false;
}

void Player::InitComponents() {

    this->createInfoComponent("Player", 0, 100, 100, 0, 100);
    this->createHitboxComponent(this->sprite, 0, 0, 60, 60);
}

//--------------------------------------| CONSTRUCTOR & DESTRUCTOR 

Player::Player(float x, float y, sf::Texture &texture_sheet) {

    this->InitVariables();
    this->InitComponents();
    this->setPosition(x,y);
    
    this->createMovementComponent(100.f, 5.f, 3.f);
    this->createAnimationComponent(texture_sheet);

    this->animationComponent->addAnimation("WALK_DOWN",  5.0f, 0, 0, 2, 0, 60, 60);
    this->animationComponent->addAnimation("WALK_LEFT",  5.0f, 0, 1, 2, 1, 60, 60);
    this->animationComponent->addAnimation("WALK_RIGHT", 5.0f, 0, 2, 2, 2, 60, 60);
    this->animationComponent->addAnimation("WALK_UP",    5.0f, 0, 3, 2, 3, 60, 60);
}

Player::~Player() {}

void Player::update(const float &dt) {

    this->movementComponent->update(dt);
    this->hitboxcomponent->update(dt);

    if(this->movementComponent->getState(MOVING_RIGHT))
        
        this->animationComponent->play("WALK_RIGHT", dt, this->movementComponent->getVelocity().x, this->movementComponent->getMaxVelocity(), false);
    
    else if(this->movementComponent->getState(MOVING_LEFT))
        
        this->animationComponent->play("WALK_LEFT", dt);
    
    else if(this->movementComponent->getState(MOVING_UP))
        
        this->animationComponent->play("WALK_UP", dt);
    
    else if(this->movementComponent->getState(MOVING_DOWN))
        
        this->animationComponent->play("WALK_DOWN",dt);
}

//--------------------------------------| FUNCTIONS
