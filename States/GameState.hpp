#ifndef __STATES_GAMESTATE_HPP__
#define __STATES_GAMESTATE_HPP__

#include "../src/State.hpp"

class GameState : public State {
    
    public:

        GameState(sf::RenderWindow *window, std::map<std::string, int> *supportesKeys, std::stack<State*> *states);
        virtual ~GameState();

        void updateInput(const float &dt);
        void update(const float &dt);
        void render(sf::RenderTarget* target = NULL);        

        

    private:
    
        void InitKeyBinds();
        void InitTextures();
        void InitPlayers();

        Player *player;
};

#endif //! __STATES_GAMESTATE_HPP__