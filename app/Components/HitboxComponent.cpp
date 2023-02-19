#include "HitboxComponent.hpp"

HitboxComponent::HitboxComponent(sf::Sprite &sprite, float offset_x, float offset_y, float width, float height) : 
    sprite(sprite),
    offset(offset_x, offset_y) {

    this->hitbox.setSize(sf::Vector2f(width, height));
    this->hitbox.setPosition(this->sprite.getPosition().x + offset_x, this->sprite.getPosition().y + offset_y);
    this->hitbox.setFillColor(sf::Color::Transparent);

    //! --------------------- !//
    //! REMOVE BEFORE COMMITS !//
    //! --------------------- !//

    this->hitbox.setOutlineThickness(1.f);
    this->hitbox.setOutlineColor(sf::Color::Green);

    //! --------------------- !//
    //! REMOVE BEFORE COMMITS !//
    //! --------------------- !//
}

HitboxComponent::~HitboxComponent() {}

bool HitboxComponent::checkIntersect(const sf::FloatRect &frect) {

    return this->hitbox.getGlobalBounds().intersects(frect);
}

void HitboxComponent::update(const float &dt) {

    this->hitbox.setPosition(this->sprite.getPosition().x + this->offset.x, this->sprite.getPosition().y + this->offset.y);
}

void HitboxComponent::render(sf::RenderTarget &target) {

    target.draw(this->hitbox);
}
