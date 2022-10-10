#ifndef __ENTITIES_ENTITY_HPP__
#define __ENTITIES_ENTITY_HPP__

#include "../Components/MovementComponent.hpp"

/// @brief Parent class for personnages with sprites who have textures and movements.
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

        void setTexture(sf::Texture &texture);
        void createMovementComponent(const float maxVelocity);
    
    protected:
    
        sf::Sprite sprite;
        MovementComponent *movementComponent;

    private:

        void InitVariables();

        //-------------------------------| VARIABLES

};

#endif //! __ENTITIES_ENTITY_HPP__