#ifndef __ENTITIES_PLAYER_HPP__
#define __ENTITIES_PLAYER_HPP__

#include "../Entity.hpp"

class Player : public Entity {

    public:

        Player(float x, float y, sf::Texture &texture_sheet);
        virtual ~Player();

        //--------------------------------------| FUNCTIONS

        virtual void update(const float &dt);
    
    private:

        //--------------------------------------| VARIABLES

        bool attacking = false;

        //--------------------------------------| INITIALISATION FUNCTIONS

        void InitVariables();
        void InitComponents();
};

#endif //! __ENTITIES_PLAYER_HPP__