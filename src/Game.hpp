#ifndef __GAME__HPP__
#define __GAME__HPP__

#include "../States/MainMenuState.hpp"

class Game {
    
    public:

        //-------------------------------| CONSTRUCTOR / DESTRUCTOR

        Game();
        virtual ~Game();

        //-------------------------------| FUNCTIONS

        void endApplication();

        void updateSFMLEvents();
        void update();
        void updateDt();
        void render();
        void run();
    
    private:

        //-------------------------------| VARIABLES

        sf::RenderWindow *window;
        std::vector<sf::VideoMode> videoModes;
        sf::ContextSettings windowSettings;
        bool fullscreen;
        sf::Event sfEvent;

        sf::Clock dtClock;
        float dt;

        std::stack<State*> states;
        std::map<std::string, int> supportedKeys;

        //-------------------------------| INITIALIZER FUNCTIONS

        void InitVariables();
        void InitWindow();
        void InitKeys();
        void InitStates();
};

#endif // ! __GAME__HPP__