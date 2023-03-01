#ifndef __EDITORSTATE__HPP__
#define __EDITORSTATE__HPP__

#include "../State.hpp"

class EditorState: public State {

    public:

        EditorState(sf::RenderWindow *window, std::map<std::string, int> *supportesKeys, std::stack<State*> *states);
        virtual ~EditorState();

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

        Logger logger;

        sf::Font font;


};

#endif //! __EDITORSTATE__HPP__