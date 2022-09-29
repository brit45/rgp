#include "GameState.hpp"

//-------------------------------| INITIALIZER

void GameState::InitKeyBinds() {

    std::ifstream ifs("Config/gamestate_keybinds.ini");

    if(!ifs.is_open()) {

        this->keybinds["MOVE_UP"]       = this->supportedKeys->at("Up");
        this->keybinds["MOVE_LEFT"]     = this->supportedKeys->at("Left");
        this->keybinds["MOVE_RIGHT"]    = this->supportedKeys->at("Right");
        this->keybinds["MOVE_DOWN"]     = this->supportedKeys->at("Down");
        this->keybinds["QUIT"]          = this->supportedKeys->at("Esc");

        std::ofstream ofs("Config/gamestate_keybinds.ini");

        ofs << "MOVE_DOWN" << " " << "Down" << std::endl;
        ofs << "QUIT" << " " << "Esc" << std::endl;
        ofs << "MOVE_LEFT" << " " << "Left" << std::endl;
        ofs << "MOVE_RIGHT" << " " << "Right" << std::endl;
        ofs << "MOVE_UP" << " " << "Up";

        ofs.close();
    }
    else {

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


void GameState::InitTextures() {

    this->textures["PLAYER_IDLE"].loadFromFile("assets/Images/Sprites/Player/Elf.png");

}

void GameState::InitPlayers() {

    if(this->player = new Player(0,0, &this->textures["PLAYER_IDLE"])) {
        
        throw("ERROR::GAMESTATE → [ FAILED TO FOUND TEXTURE OF PLAYER_IDLE ]\n");
    }
}

//-------------------------------| CONSTRUCTOR / DESTRUCTOR

GameState::GameState(sf::RenderWindow *window, std::map<std::string, int> *supportesKeys, std::stack<State*> *states) : 
    State(window, supportesKeys, states) {

        this->InitKeyBinds();
        this->InitTextures();
        this->InitPlayers();
    }

GameState::~GameState() {

    delete this->player;
}

//-------------------------------| FUNCTIONS

void GameState::updateInput(const float &dt) {


    if(sf::Keyboard::isKeyPressed((sf::Keyboard::Key) this->keybinds.at("MOVE_UP"))) {
        
        this->player->move(dt, 0.f, -1.f);
    }
    else if(sf::Keyboard::isKeyPressed((sf::Keyboard::Key) this->keybinds.at("MOVE_LEFT"))) {

        this->player->move(dt, -1.f, 0.f);
    }
    else if(sf::Keyboard::isKeyPressed((sf::Keyboard::Key) this->keybinds.at("MOVE_RIGHT"))) {

        this->player->move(dt, 1.f, 0.f);
    }
    else if(sf::Keyboard::isKeyPressed((sf::Keyboard::Key) this->keybinds.at("MOVE_DOWN"))) {

        this->player->move(dt, 0.f, 1.f);
    }
    else if(sf::Keyboard::isKeyPressed((sf::Keyboard::Key) this->keybinds.at("QUIT"))) {

        this->endState();
    }
}

void GameState::update(const float &dt) {
    
    this->updateMousePositions();
    this->updateInput(dt);
    this->player->update(dt);

}

void GameState::render(sf::RenderTarget *target) {

    if(!target)
        target = this->window;

    this->player->render(target);
}