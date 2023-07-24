#include "AnimationComponent.hpp"

AnimationComponent::AnimationComponent(sf::Sprite &sprite, sf::Texture &texture_sheet) :
    sprite(sprite),
    textureSheet(texture_sheet),
    lastAnimation(NULL),
    priorityAnimation(NULL) {}

AnimationComponent::~AnimationComponent() {

    for(auto &i : this->animations) {

        delete i.second;
    }
}

void AnimationComponent::addAnimation(const std::string key, float animation_Timer, int start_frame_x, int start_frame_y, int frame_x, int frame_y, int width, int height) {

    this->animations[key] = new Animation(this->sprite, this->textureSheet, animation_Timer, start_frame_x, start_frame_y, frame_x, frame_y, width, height);
}

void AnimationComponent::play(const std::string key, const float &dt, const bool priority) {

    if(priority) {

        this->priorityAnimation = this->animations[key];
    }

    if(this->priorityAnimation) {

        if(this->priorityAnimation == this->animations[key]) {

            if(this->lastAnimation != this->animations[key]) {
            
                if(this->lastAnimation == NULL) {

                    this->lastAnimation = this->animations[key];
                }
                else {
                
                    this->lastAnimation->reset();
                    this->lastAnimation = this->animations[key];
                }
            }

            if(this->animations[key]->play(dt)) {

                this->priorityAnimation = NULL;
            }
        }

    }
    else {

        if(this->lastAnimation != this->animations[key]) {
            
            if(this->lastAnimation == NULL) {

                this->lastAnimation = this->animations[key];
            }
            else {
            
                this->lastAnimation->reset();
                this->lastAnimation = this->animations[key];
            }
        }

        this->animations[key]->play(dt);
    }
}

void AnimationComponent::play(const std::string key, const float & dt, const float & modifier, const float & modifier_max, const bool priority) {

    if(priority) {

        this->priorityAnimation = this->animations[key];
    }

    if(this->priorityAnimation) {

        if(this->priorityAnimation == this->animations[key]) {

            if(this->lastAnimation != this->animations[key]) {
            
                if(this->lastAnimation == NULL) {

                    this->lastAnimation = this->animations[key];
                }
                else {
                
                    this->lastAnimation->reset();
                    this->lastAnimation = this->animations[key];
                }
            }

            if(this->animations[key]->play(dt, abs(modifier / modifier_max))) {

                this->priorityAnimation = NULL;
            }
        }

    }
    else {

        if(this->lastAnimation != this->animations[key]) {
            
            if(this->lastAnimation == NULL) {

                this->lastAnimation = this->animations[key];
            }
            else {
            
                this->lastAnimation->reset();
                this->lastAnimation = this->animations[key];
            }
        }

        this->animations[key]->play(dt, abs(modifier / modifier_max));
    }

}

//------------------------------------------------------------| ANIMATE CLASS

AnimationComponent::Animation::Animation(sf::Sprite &sprite, sf::Texture &textureSheet, float animation_Timer, int start_frame_x, int start_frame_y, int frame_x, int frame_y, int width, int height) : 
    sprite(sprite),
    textureSheet(textureSheet),
    animationTimer(animation_Timer),
    width(width),
    height(height) {

    this->startRect = sf::IntRect(start_frame_x * width, start_frame_y * height, width, height);
    this->endRect = sf::IntRect(frame_x * width, frame_y * height, width, height);

    this->timer = 0.0f;

    this->currentRect = this->startRect;

    this->sprite.setTexture(this->textureSheet, true);
    this->sprite.setTextureRect(this->startRect);
}

bool AnimationComponent::Animation::play(const float &dt) {

    bool done = false;

    this->timer += 100.0f * dt;
    
    if(this->timer >= this->animationTimer) {

        this->timer = 0.0f;

        if(this->currentRect != this->endRect) {

            this->currentRect.left += this->width;
        }
        else {

            this->currentRect.left = this->startRect.left;
            done = true;
        }

        this->sprite.setTextureRect(this->currentRect);
    }

    return done;
}

bool AnimationComponent::Animation::play(const float &dt, float mod_percent) {
    
    bool done = false;

    if(mod_percent < 0.5f)
        mod_percent = 0.5f;

    this->timer += mod_percent * 100.0f * dt;
    
    if(this->timer >= this->animationTimer) {

        this->timer = 0.0f;

        if(this->currentRect != this->endRect) {

            this->currentRect.left += this->width;
        }
        else {

            this->currentRect.left = this->startRect.left;
            done = true;
        }

        this->sprite.setTextureRect(this->currentRect);
    }

    return done;
}

void AnimationComponent::Animation::stop() {}

void AnimationComponent::Animation::reset() {

    this->timer = 0.0f;
    this->currentRect = this->startRect;
}