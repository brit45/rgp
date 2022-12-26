#ifndef __STATES_MAINMENUSTATE_HPP__
#define __STATES_MAINMENUSTATE_HPP__

#include "GameState.hpp"
#include "../Ressource/Button.hpp"

class MainMenuState : public State {

    public:

        MainMenuState(sf::RenderWindow *window, std::map<std::string, int> *supportesKeys, std::stack<State*> *states);
        virtual ~MainMenuState();

        void endState();
        void updateButton();
        void updateInput(const float &dt);
        void update(const float &dt);
        void render(sf::RenderTarget* target = NULL);
        void renderButton(sf::RenderTarget* target = NULL);

        

    private:
    
        void InitFont();
        void InitKeyBinds();
        void InitButton();

        Button *gamestate_btn;

        std::map<std::string, Button*>  buttons;

        sf::Font font;
        sf::RectangleShape background;

};

#endif //! __STATES_MAINMENUSTATE_HPP__