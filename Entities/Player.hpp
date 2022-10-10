#ifndef __ENTITIES_PLAYER_HPP__
#define __ENTITIES_PLAYER_HPP__

#include "Entity.hpp"

class Player : public Entity {

    public:

        Player(float x, float y, sf::Texture &texture);
        virtual ~Player();

        //--------------------------------------| FUNCTIONS
    
    private:

        //--------------------------------------| VARIABLES

        //--------------------------------------| INITIALISATION FUNCTIONS

        void InitVariables();
        void InitComponents();
};

#endif //! __ENTITIES_PLAYER_HPP__