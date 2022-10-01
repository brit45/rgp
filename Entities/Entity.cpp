#include "Entity.hpp"

//-------------------------------| CONSTRUCTOR / DESTRUCTOR

Entity::Entity() {

    this->InitVariables();
}

Entity::~Entity() {

    delete this->sprite;
    delete this->texture;
}

//-------------------------------| COMPONENT FUNCTIONS

void Entity::createSprite(sf::Texture *texture) {

    this->texture = texture;
    this->sprite = new sf::Sprite(*this->texture);
    
}

void Entity::createMovementComponent(float maxVelocity) {

    this->movementComponen = new MouvementComponent(maxVelocity);
}

//-------------------------------| FUNCTIONS

void Entity::InitVariables() {
    
    this->texture       = NULL;
    this->sprite        = NULL;
    this->movementComponent = NULL;
}

void Entity::setPosition(const float x, const float y) {

    if(this->sprite)
        this->sprite->setPosition(x,y);

}

void Entity::update(const float &dt) {}

void Entity::render(sf::RenderTarget *target) {
    
    if(this->sprite)
        target->draw(*this->sprite);
}

void Entity::move(const float &dt, const float dir_x, const float dir_y) {
    
    if(this->sprite && this->movementComponent) {
        
        this->movementComponent->move(dir_x, dir_y); // Set Velocity
        this->sprite->move(this->movementComponent->getVelocity() * dt); // Use Velocity
    }
}

