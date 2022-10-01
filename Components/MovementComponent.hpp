#ifndef __COMPONENT_MOUVEMENTCOMPONENT_HPP__
#define __COMPONENT_MOUVEMENTCOMPONENT_HPP__

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

class MouvementComponent {

    public:

        MouvementComponent(float maxVeloxity);
        virtual ~MouvementComponent();

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

#endif //! __COMPONENT_MOUVEMENTCOMPONENT_HPP__