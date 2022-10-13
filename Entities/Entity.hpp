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

        /**
         * @brief Update of Entity logic.
         * 
         * @param dt Timer of global application.
         */
        virtual void update(const float &dt);

        /**
         * @brief Show entity on global application.
         * 
         * @param target Draw entity on global application.
         */
        virtual void render(sf::RenderTarget *target);

        /**
         * @brief Instance of movement of entity.
         * 
         * @param dt Time on global application.
         * @param x  Position on Width.
         * @param y  Position on Height.
         */
        virtual void move(const float &dt, const float x, const float y);

        /**
         * @brief Set the Position.
         * 
         * @param x Width
         * @param y Height.
         */
        virtual void setPosition(const float x, const float y);

        //-------------------------------| COMPONENT FUNCTIONS

        /**
         * @brief Set the Texture.
         * 
         * @param texture 
         */
        void setTexture(sf::Texture &texture);

        /**
         * @brief Create a Movement Component.
         * 
         * @param maxVelocity Velocity Max.
         */
        void createMovementComponent(const float maxVelocity);
    
    protected:
    
        sf::Sprite sprite;
        MovementComponent *movementComponent;

    private:

        void InitVariables();

        //-------------------------------| VARIABLES

};

#endif //! __ENTITIES_ENTITY_HPP__