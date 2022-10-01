#include "MovementComponent.hpp"

MovementComponent::MovementComponent(float maxVelocity):
    maxVelocity(maxVelocity) {}

MovementComponent::~MovementComponent() {}


//------------------------------------------------------------| FUNCTIONS

void MovementComponent::update(const float &dt) {}

void MovementComponent::move(const float dir_x, const float dir_y) {

    this->velocity.x = this->maxVelocity * dir_x;
    this->velocity.y = this->maxVelocity * dir_y;
}

//------------------------------------------------------------| ACCESSORS

const sf::Vector2f &MovementComponent::getVelocity() const {

    return this->velocity;
}

