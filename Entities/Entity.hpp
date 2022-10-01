#ifndef __ENTITIES_ENTITY_HPP__
#define __ENTITIES_ENTITY_HPP__

#include "../Components/MovementComponent.hpp"

class Entity {

    public:
        
        //-------------------------------| CONSTRUCTOR / DESTRUCTOR
        
        Entity();
        virtual ~Entity();

        //-------------------------------| FUNCTIONS

        virtual void update(const float &dt);
        virtual void render(sf::RenderTarget *target);

        virtual void move(const float &dt, const float x, const float y);

        virtual void setPosition(const float x, const float y);

        //-------------------------------| COMPONENT FUNCTIONS

        void createSprite(sf::Texture *texture);
        void createMovementComponent(const float maxVelocity);
    
    protected:

        sf::Texture *texture;
        sf::Sprite *sprite;
        MouvementComponent *movementComponent;

    private:

        void InitVariables();

        //-------------------------------| VARIABLES

};

#endif //! __ENTITIES_ENTITY_HPP__