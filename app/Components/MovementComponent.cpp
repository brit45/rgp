#include "MovementComponent.hpp"

MovementComponent::MovementComponent(sf::Sprite &sprite, float maxVelocity, float acceleration, float deceleration):
    acceleration(acceleration),
    deceleration(deceleration),
    sprite(sprite),
    maxVelocity(maxVelocity) {}

MovementComponent::~MovementComponent() {}


//------------------------------------------------------------| FUNCTIONS

void MovementComponent::update(const float &dt) {
    
    //? Deceleration

    if(this->velocity.x > 0.f) {

        this->velocity.x -= this->deceleration;
        
        if(this->velocity.x < 0.f ) {
            
            this->velocity.x = 0.f;
        }
    }
    else if(this->velocity.x < 0.f) {

        this->velocity.x += this->deceleration;
        
        if(this->velocity.x > 0.f ) {
            
            this->velocity.x = 0.f;
        }
    }

    if(this->velocity.y > 0.f) {

        this->velocity.y -= this->deceleration;
        
        if(this->velocity.y < 0.f ) {
            
            this->velocity.y = 0.f;
        }
    }
    else if(this->velocity.y < 0.f) {

        this->velocity.y += this->deceleration;
        
        if(this->velocity.y > 0.f ) {
            
            this->velocity.y = 0.f;
        }
    }
    
    //? Final Move
    this->sprite.move(this->getVelocity() * dt); //? Use Velocity
}

void MovementComponent::move(const float dir_x, const float dir_y, const float &dt) {

    //? Acceleration

    this->velocity.x += this->acceleration * dir_x;

    if(this->velocity.x > 0.f) {  // Check for Right

        if(this->velocity.x > this->maxVelocity) {

            this->velocity.x = this->maxVelocity;
        }
    }
    else if(this->velocity.x < 0.f) { // Check for Left

        if(this->velocity.x < -this->maxVelocity) {

            this->velocity.x = -this->maxVelocity;
        }

    }

    this->velocity.y += this->acceleration * dir_y;

    if(this->velocity.y > 0.f) {  // Check for Bottom

        if(this->velocity.y > this->maxVelocity) {

            this->velocity.y = this->maxVelocity;
        }
    }
    else if(this->velocity.y < 0.f) { // Check for Top

        if(this->velocity.y < -this->maxVelocity) {

            this->velocity.y = -this->maxVelocity;
        }

    }

}

//------------------------------------------------------------| ACCESSORS

const sf::Vector2f &MovementComponent::getVelocity() const {

    return this->velocity;
}

const bool MovementComponent::idle() const {

    if(this->velocity.x == 0.0f && this->velocity.y == 0.0f)
        return true;
    else
        return false;
}