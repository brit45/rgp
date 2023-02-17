#include "EditorState.hpp"

//-------------------------------| INITIALIZER

void EditorState::InitVariables() {}

void EditorState::InitBackground() {}

void EditorState::InitKeyBinds() {

    std::ifstream ifs("Config/editorstate_keybinds.ini");

    if(ifs.is_open()) {

        std::string key = "";
        std::string key2 = "";

        while(ifs >> key >> key2) {

            try {

                this->keybinds[key] = this->supportedKeys->at(key2);
            }
            catch(std::out_of_range e) {
                
                printf("Error : %s\n", e.what());
                exit(1);
            }
        }
        
    }

    ifs.close();
}

void EditorState::InitFont() {

    if(!this->font.loadFromFile("assets/Fonts/Latin/police.ttf")) {
        
        throw("ERROR::EditorState → [ COULD NOT FOUND FONT ]\n");
        return;
    }

}

void EditorState::InitButton() {}

//-------------------------------| CONSTRUCTOR / DESTRUCTOR

EditorState::EditorState(sf::RenderWindow *window, std::map<std::string, int> *supportesKeys, std::stack<State*> *states) : 
    State(window, supportesKeys, states) {

        std::cout << "[ INFO|DEBUG ]\t->\tStart view ` EditorState `." << std::endl;
        
        this->InitVariables();
        this->InitBackground();
        this->InitFont();
        this->InitKeyBinds();
        this->InitButton();
    }

EditorState::~EditorState() {
    
    std::cout << "[ INFO|DEBUG ]\t->\tClose view of ` EditorState `." << std::endl;

    for(auto it = this->buttons.begin(); it != this->buttons.end(); it++) {

        delete it->second;
    }
}
//-------------------------------| FUNCTIONS

void EditorState::updateInput(const float &dt) {

    if(sf::Keyboard::isKeyPressed((sf::Keyboard::Key) this->keybinds.at("QUIT"))) {
        this->endState();
    }
}

void EditorState::updateButton() {

    for(auto &it : this->buttons) {

        it.second->update(this->mousePosView);
    }
}

void EditorState::update(const float &dt) {
    
    this->updateMousePositions();
    this->updateInput(dt);
    this->updateButton();
    
}

void EditorState::render(sf::RenderTarget *target) {

    if(!target)
        target = this->window;

    this->renderButton(target);
    
}

void EditorState::renderButton(sf::RenderTarget* target) {

    if(!target)
        target = this->window;

    for(auto &it : this->buttons) {

        it.second->render(target);
    }
}
