#include "Entity.hpp"

//-------------------------------| CONSTRUCTOR / DESTRUCTOR

Entity::Entity() {

    this->InitVariables();
}

Entity::~Entity() {

    delete this->movementComponent;
    delete this->animationComponent;
}

//-------------------------------| COMPONENT FUNCTIONS

void Entity::setTexture(sf::Texture &texture) {

    this->sprite.setTexture(texture);
    
}

void Entity::createMovementComponent(float maxVelocity, const float acceleration, const float deceleration) {

    this->movementComponent = new MovementComponent(this->sprite, maxVelocity, acceleration, deceleration);
}

void Entity::createAnimationComponent(sf::Texture &texture_sheet) {

    this->animationComponent = new AnimationComponent(this->sprite, texture_sheet);
}

//-------------------------------| FUNCTIONS

void Entity::createInfoComponent(std::string name, uint level, uint hp, uint hpM, uint exp, uint expM) {

    this->infoComponent = new InfoComponent(name, level, hp, hpM, exp, expM);
}

void Entity::InitVariables() {}

void Entity::InitComponents() {

    this->movementComponent = NULL;
    this->animationComponent = NULL;
    this->infoComponent = NULL;
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

