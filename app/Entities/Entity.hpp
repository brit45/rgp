#ifndef __ENTITIES_ENTITY_HPP__
#define __ENTITIES_ENTITY_HPP__

#include "../Components/MovementComponent.hpp"
#include "../Components/AnimationComponent.hpp"
#include "../Components/HitboxComponent.hpp"
#include "../Components/InfoComponent.hpp"
#include "../Resource/Logger.hpp"

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
         * @param acceleration Velocity Up.
         * @param deceleration Velocity down.
         */
        void createMovementComponent(const float maxVelocity, const float acceleration, const float deceleration);

        /**
         * @brief Create a Animation Component.
         * 
         * @param texture_sheet 
         */
        void createAnimationComponent(sf::Texture &texture_sheet);

        /**
         * @brief Create a Hitbox Component.
         * 
         * @param sprite
         * @param offset_x 
         * @param offset_y
         * @param width
         * @param height
         */
        void createHitboxComponent(sf::Sprite &sprite, float offset_x , float offset_y, float width, float height);

        /**
         * @brief Create a Info Component.
         * 
         * @param name 
         * @param level 
         * @param hp 
         * @param hpM 
         * @param exp 
         * @param expM 
         */
        void createInfoComponent(std::string name, uint level, uint hp, uint hpM, uint exp, uint expM);
    
    protected:
    
        sf::Sprite sprite;
        MovementComponent   *movementComponent;
        AnimationComponent  *animationComponent;
        HitboxComponent     *hitboxcomponent;
        InfoComponent       *infoComponent;

        Logger log;

    private:

        void InitVariables();
        
        void InitComponents();

        //-------------------------------| VARIABLES

};

#endif //! __ENTITIES_ENTITY_HPP__