#ifndef __STATE_HPP__
#define __STATE_HPP__

#include "../Entities/Entity.hpp"

class State {

    public:

        //-------------------------------| CONSTRUCTOR / DESTRUCTOR

        State(sf::RenderWindow *window, std::map<std::string, int> *supportesKeys, std::stack<State*> *states);
        virtual ~State();

        //-------------------------------| FUNCTIONS

        const bool& getQuit() const;
        
        void endState();

        virtual void updateMousePositions();
        virtual void updateInput(const float &dt) = 0;
        virtual void update(const float &dt) = 0;
        virtual void render(sf::RenderTarget* target = NULL) = 0;

    
    protected:

        std::stack<State*> *states;
        sf::RenderWindow *window;
        std::map<std::string, int> *supportedKeys;
        std::map<std::string, int> keybinds;

        virtual void InitKeyBinds() = 0;

        sf::Vector2i mousePosScreen;
        sf::Vector2i mousePosWindow;
        sf::Vector2f mousePosView;

        bool quit;


    private:

        std::vector<sf::Texture> texture;
};

#endif // !__STATE_HPP__