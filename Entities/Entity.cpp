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
    this->sprite->setTexture(*this->texture);
    
}

//-------------------------------| FUNCTIONS

void Entity::InitVariables() {
    
    this->texture       = NULL
    this->sprite        = NULL;
    this->movementSpeed = 100.0f;
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
    
    if(this->sprite) {

        this->sprit->.move(dir_x * this->movementSpeed * dt, dir_y * this->movementSpeed * dt);
    }
}

