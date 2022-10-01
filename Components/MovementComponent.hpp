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

        MovementComponent(float maxVeloxity);
        virtual ~MovementComponent();

        //-------------------------------| FUNCTIONS

        void update(const float &dt);
        void move(const float dir_x, const float dir_y);

        //-------------------------------| ACCESSORS

        const sf::Vector2f &getVelocity() const;
    
    private:

        //-------------------------------| VARIABLES

        float           maxVelocity;
        sf::Vector2f    velocity;
        sf::Vector2f    acceleration;
        sf::Vector2f    deceleration;

        //-------------------------------| INITIALIZER FUNCTIONS

        void InitVariables();
};

#endif //! __COMPONENT_MOVEMENTCOMPONENT_HPP__