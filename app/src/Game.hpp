#ifndef __GAME__HPP__
#define __GAME__HPP__

#include "../States/MainMenu/MainMenuState.hpp"

class Game {
    
    public:

        //-------------------------------| CONSTRUCTOR / DESTRUCTOR

        Game();
        virtual ~Game();

        //-------------------------------| FUNCTIONS

        /// @brief Close Game Interface.
        void endApplication();

        /// @brief Update SFML Events.
        void updateSFMLEvents();

        /// @brief Update components system.
        void update();

        /// @brief Update Timer system.
        void updateDt();

        /// @brief Generate GUI interface.
        void render();

        /// @brief Launch Game logic.
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

        /// @brief Initialize local variable
        void InitVariables();

        /// @brief Initialize interface GUI.
        void InitWindow();

        /// @brief Initialize gestion of key control.
        void InitKeys();

        /// @brief Initialize initial States interfaces.
        void InitStates();
};

#endif // ! __GAME__HPP__