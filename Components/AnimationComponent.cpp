#include "AnimationComponent.hpp"

AnimationComponent::AnimationComponent(sf::Sprite &sprite, sf::Texture &texture_sheet) :
    sprite(sprite),
    textureSheet(texture_sheet) {}

AnimationComponent::~AnimationComponent() {}

void AnimationComponent::addAnimation(const std::string key) {}

void AnimationComponent::startAnimation(const std::string animation) {}

void AnimationComponent::pauseAnimation(const std::string animation) {}

void AnimationComponent::resetAnimation(const std::string animation) {}

void AnimationComponent::update(const float &dt) {}

//------------------------------------------------------------| ANIMATE CLASS

AnimationComponent::Animation::Animation(sf::Sprite &sprite, sf::Texture &textureSheet, float animation_Timer, int start_x, int start_y, int end_x, int end_y, int width, int height) : 
    sprite(sprite),
    textureSheet(textureSheet),
    animationTimer(animation_Timer),
    width(width),
    height(height) {

    this->startRect = sf::IntRect(start_x, start_y, width, height);
    this->endRect = sf::IntRect(end_x, end_y, width, height);

    this->currentRect = this->startRect;

    this->sprite.setTexture(this->textureSheet, true);
    this->sprite.setTextureRect(this->startRect);
}

void AnimationComponent::Animation::update(const float &dt) {

    this->timer = 10.0f * dt;
    
    if(this->timer >= this->animationTimer) {

        this->timer = 0.0f;

        if(this->currentRect != this->endRect) {

            this->currentRect.left += this->width;
        }
        else {

            this->currentRect.left = this->startRect.left;
        }
    }
}

void AnimationComponent::Animation::play() {}

void AnimationComponent::Animation::stop() {}

void AnimationComponent::Animation::reset() {}