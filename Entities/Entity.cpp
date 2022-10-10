#include "Entity.hpp"

//-------------------------------| CONSTRUCTOR / DESTRUCTOR

Entity::Entity() {

    this->InitVariables();
}

Entity::~Entity() {

    delete this->movementComponent;
}

//-------------------------------| COMPONENT FUNCTIONS

void Entity::setTexture(sf::Texture &texture) {

    this->sprite.setTexture(texture);
    
}

void Entity::createMovementComponent(float maxVelocity) {

    this->movementComponent = new MovementComponent(this->sprite, maxVelocity);
}

//-------------------------------| FUNCTIONS

void Entity::InitVariables() {
    
    this->movementComponent = NULL;
}

void Entity::setPosition(const float x, const float y) {

    this->sprite.setPosition(x,y);

}

void Entity::update(const float &dt) {}

void Entity::render(sf::RenderTarget *target) {

    target->draw(this->sprite);
}

void Entity::move(const float &dt, const float dir_x, const float dir_y) {
    
    if(this->movementComponent) {
        
        this->movementComponent->move(dir_x, dir_y, dt); // Set Velocity
    }
}

