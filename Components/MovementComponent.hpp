#ifndef __COMPONENT_MOVEMENTCOMPONENT_HPP__
#define __COMPONENT_MOVEMENTCOMPONENT_HPP__

#include <iostream>
#include <ctime>
#include <cstdlib>
#include <vector>
#include <fstream>
#include <sstream>
#include <stack>
#include <map>

#include <SFML/System.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Network.hpp>

class MovementComponent {

    public:

        /**
         * @brief Construct a new Movement Component.
         * 
         * @param sprite Entity.
         * @param maxVeloxity Velocity Max.
         */
        MovementComponent(sf::Sprite &sprite, float maxVeloxity);
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
    
    private:

        //-------------------------------| VARIABLES

        float           maxVelocity;
        sf::Vector2f    velocity;
        sf::Vector2f    acceleration;
        sf::Vector2f    deceleration;
        sf::Sprite      &sprite;

        //-------------------------------| INITIALIZER FUNCTIONS

        void InitVariables();
};

#endif //! __COMPONENT_MOVEMENTCOMPONENT_HPP__