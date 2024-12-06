#ifndef __EDITORSTATE__HPP__
#define __EDITORSTATE__HPP__

#include "../State.hpp"
#include "../../../app/Components/ContentComponent.hpp"
#include "../../../app/Components/SoundComponent.hpp"
#include "../../../app/Components/PathComponent.hpp"
#include "../../../app/Entities/Player/Girl.hpp"
#include "../../../app/Components/OBJModelComponent.hpp"

#include <map>

class EditorState : public State
    {

    public:
        
        EditorState(sf::RenderWindow *window, std::map<std::string, int> *supportesKeys, std::stack<State *> *states, Logger *log);
        virtual ~EditorState();

        void updateInput(const float &dt);
        void update(const float &dt);
        void render(sf::RenderTarget *target = NULL);

    private:
        
        void InitBackground();
        void InitVariables();
        void InitFont();
        void InitKeyBinds();

        void setText();

        void setTexture(std::string path, sf::Texture &texture, sf::RectangleShape &shape);

        //------------------------------------------------| COMPONENTS

        ContentComponent contentComponent;

        std::map<std::string, SoundComponent*> SoundMap;

        PathComponent *path = NULL;
        OBJModelComponent obj3d;

        //------------------------------------------------| END COMPONENTS

        sf::Font font;
        sf::Text text;
        sf::RectangleShape background;
        sf::Texture backgroundTexture;

        sf::RectangleShape perso;
        sf::Texture persoTexture;

        uint short index = 1;
        uint short indexPerso = 1;

        enum perso_type {

            GIRL_1 = 0,
            GIRL_2,
            FONT,
            BACKGROUND,
            SOUND,
            LOG,
            ASSETS
        };

        enum Sound_name {

            CLOSE,
            PAPER,
            SUNSET
        };

        uint short persoOffset = 0;

        std::map<uint, std::vector<std::string>> path_image;

        Girl *girl_1;
        Girl *girl_2;

};

#endif //! __EDITORSTATE__HPP__