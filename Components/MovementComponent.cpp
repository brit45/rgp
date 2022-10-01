#include "MovementComponent.hpp"

MouvementComponent::MouvementComponent(float maxVelocity):
    maxVelocity(maxVelocity) {}

MouvementComponent::~MouvementComponent() {}


//------------------------------------------------------------| FUNCTIONS

void MouvementComponent::update(const float &dt) {}

void MouvementComponent::move(const float dir_x, const float dir_y) {

    this->velocity.x = this->maxVelocity * dir_x;
    this->velocity.y = this->maxVelocity * dir_y;
}

//------------------------------------------------------------| ACCESSORS

const sf::Vector2f &MouvementComponent::getVelocity() const {

    return this->velocity;
}

