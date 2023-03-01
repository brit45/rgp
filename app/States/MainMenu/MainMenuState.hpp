#ifndef __STATES_MAINMENUSTATE_HPP__
#define __STATES_MAINMENUSTATE_HPP__

#include "../Game/GameState.hpp"
#include "../Editor/EditorState.hpp"
#include <fstream>

class MainMenuState : public State {

    public:

        MainMenuState(sf::RenderWindow *window, std::map<std::string, int> *supportesKeys, std::stack<State*> *states);
        virtual ~MainMenuState();

        void updateButton();
        void updateInput(const float &dt);
        void update(const float &dt);
        void render(sf::RenderTarget* target = NULL);
        void renderButton(sf::RenderTarget* target = NULL);

        

    private:
    
        void InitBackground();
        void InitVariables();
        void InitFont();
        void InitKeyBinds();
        void InitButton();

        Button *gamestate_btn;

        std::map<std::string, Button*>  buttons;

        sf::Font font;
        sf::RectangleShape background;
        sf::Texture backgroundTexture;
        
        Logger log;
        std::string Version_out;

};

#endif //! __STATES_MAINMENUSTATE_HPP__