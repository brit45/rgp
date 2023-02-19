#ifndef __COMPONENT_MOVEMENTCOMPONENT_HPP__
#define __COMPONENT_MOVEMENTCOMPONENT_HPP__

#include "Component.inl"

enum Movement_states {
    
    IDLE = 0,
    MOVING,
    MOVING_LEFT,
    MOVING_RIGHT,
    MOVING_UP,
    MOVING_DOWN
};

class MovementComponent {

    public:

        /**
         * @brief Construct a new Movement Component.
         * 
         * @param sprite Entity.
         * @param maxVeloxity Velocity Max.
         */
        MovementComponent(sf::Sprite &sprite, float maxVeloxity, float acceleration, float deceleration);
        virtual ~MovementComponent();

        //-------------------------------| FUNCTIONS

        /**
         * @brief Update of logic.
         * 
         * @param dt Timer of global application.
         */
        void update(const float &dt);

        /**
         * @brief Instance of move.
         * 
         * @param dir_x Position on Width.
         * @param dir_y Position on Height.
         * @param dt Time on global application.
         */
        void move(const float dir_x, const float dir_y, const float &dt);

        //-------------------------------| ACCESSORS

        /**
         * @brief Get the Velocity.
         * 
         * @return const sf::Vector2f& 
         */
        const sf::Vector2f &getVelocity() const;

        /**
         * @brief Detect movement states.
         * @return bool 
         */
        const bool getState(const short unsigned state) const;
    
    private:

        //-------------------------------| VARIABLES

        float           maxVelocity;
        sf::Vector2f    velocity;
        float           acceleration;
        float           deceleration;
        sf::Sprite      &sprite;

        //-------------------------------| INITIALIZER FUNCTIONS

        void InitVariables();
};

#endif //! __COMPONENT_MOVEMENTCOMPONENT_HPP__