#ifndef __STATE_HPP__
#define __STATE_HPP__

#include "../Entities/Player/Player.hpp"
#include "../Resource/Logger.hpp"
#include "../Resource/Button.hpp"

class State {

    public:

        //-------------------------------| CONSTRUCTOR / DESTRUCTOR

        /**
        * @brief 
        * @param window Window of principal app.
        * @param supportesKeys List of keys.
        * @param states List of States.
        */
        State(sf::RenderWindow *window, std::map<std::string, int> *supportesKeys, std::stack<State*> *states);
        virtual ~State();

        //-------------------------------| FUNCTIONS
        
        /**
         * @brief Get the Quit current State.
         * 
         * @return true 
         * @return false 
         */
        const bool& getQuit() const;
        
        /// @brief Quit current State.
        void endState();

        /// @brief Update the position of mouse in application.
        virtual void updateMousePositions();

        /**
         * @brief Detect the keys input.
         * 
         * @param dt Global Time of Application.
         */
        virtual void updateInput(const float &dt) = 0;

        /**
         * @brief Update of State logic.
         * 
         * @param dt Global Time of Application.
         */
        virtual void update(const float &dt) = 0;

        /**
         * @brief Show State.
         * 
         * @param target Global Application.
         */
        virtual void render(sf::RenderTarget* target = NULL) = 0;

        /// @brief List of Textures in this State.
        std::map<std::string,sf::Texture> textures;
    
    protected:

        /// List of States.
        std::stack<State*> *states;

        /// Global Application.
        sf::RenderWindow *window;

        /// List of supported keys.
        std::map<std::string, int> *supportedKeys;

        /// List of keys on SFML Keyboard code.
        std::map<std::string, int> keybinds;

        /// @brief Initialize the keys supported.
        virtual void InitKeyBinds() = 0;

        /// Position of mouse on the screen.
        sf::Vector2i mousePosScreen;

        /// Position of mouse on the global application.
        sf::Vector2i mousePosWindow;

        /// Position of mouse on the view.
        sf::Vector2f mousePosView;

        bool quit;


    private:

};

#endif // !__STATE_HPP__