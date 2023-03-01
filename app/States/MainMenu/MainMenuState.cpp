#include "MainMenuState.hpp"

//-------------------------------| INITIALIZER

void MainMenuState::InitVariables() {

    this->log.setPath("Config/history.log");
}

void MainMenuState::InitBackground() {

    this->background.setSize(

        sf::Vector2f (
        
            static_cast<float>(this->window->getSize().x),
            static_cast<float>(this->window->getSize().y)
        )
    );

    if(!this->backgroundTexture.loadFromFile("assets/Images/Backgrounds/bg1.png")) {
        
        throw("ERROR::MAINMENUSTATE → [ COULD NOT FOUND BACKGROUND IMAGE RESSOURCE ]\n");
        return;
    }
    this->background.setTexture(&this->backgroundTexture);
}

void MainMenuState::InitKeyBinds() {

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

void MainMenuState::InitFont() {

    if(!this->font.loadFromFile("assets/Fonts/Latin/police.ttf")) {
        
        throw("ERROR::MAINMENUSTATE → [ COULD NOT FOUND FONT ]\n");
        return;
    }

}

void MainMenuState::InitButton() {

    this->buttons["NEW"] =  new Button(
        {100,100},
        {150,50},
        _("New Game"),
        &this->font,
        sf::Color(70,70,70,200),
        sf::Color(150,150,150,255),
        sf::Color(20,20,20,200)
    );

    this->buttons["CONTINUE"] =  new Button(
        {100,150},
        {150,50},
        _("Continue"),
        &this->font,
        sf::Color(70,70,70,200),
        sf::Color(150,150,150,255),
        sf::Color(20,20,20,200)
    );

    /**
     * @translate Button of menu for show configuration panel.
     */
    this->buttons["CONF"] =  new Button(
        {100,200},
        {150,50},
        _("Config"),
        &this->font,
        sf::Color(70,70,70,200),
        sf::Color(150,150,150,255),
        sf::Color(20,20,20,200)
    );

    this->buttons["QUIT"] =  new Button(
        {100,250},
        {150,50},
        _("EXIT"),
        &this->font,
        sf::Color(170,70,70,200),
        sf::Color(160,150,150,255),
        sf::Color(120,20,20,200)
    );


}

//-------------------------------| CONSTRUCTOR / DESTRUCTOR

MainMenuState::MainMenuState(sf::RenderWindow *window, std::map<std::string, int> *supportesKeys, std::stack<State*> *states) : 
    State(window, supportesKeys, states) {

        
        this->InitVariables();
        this->InitBackground();
        this->InitFont();
        this->InitKeyBinds();
        this->InitButton();
        
        this->log.Info("VIEW", "Start Game ` Menus `.");
    }

MainMenuState::~MainMenuState() {
    
    this->log.Info("VIEW", "Close view of ` Menus `.");

    for(auto it = this->buttons.begin(); it != this->buttons.end(); it++) {

        delete it->second;
    }
}

//-------------------------------| FUNCTIONS

void MainMenuState::updateInput(const float &dt) {

   
}

void MainMenuState::updateButton() {

    for(auto &it : this->buttons) {

        it.second->update(this->mousePosView);
    }

    if(this->buttons["NEW"]->isPressed()) {
        
        this->states->push(new GameState(this->window, this->supportedKeys, this->states));
    }

    if(this->buttons["QUIT"]->isPressed()) {
        
        this->endState();
    }

    if(this->buttons["CONF"]->isPressed()) {

        this->states->push(new EditorState(this->window, this->supportedKeys, this->states));
    }
}

void MainMenuState::update(const float &dt) {
    
    this->updateMousePositions();
    this->updateInput(dt);
    this->updateButton();
    
}

void MainMenuState::render(sf::RenderTarget *target) {

    if(!target)
        target = this->window;

    target->draw(this->background);

    this->renderButton(target);

    //!               .
    //! REMOVE LATER /!\
    //! ¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯

    if(this->Version_out.empty()) {

        std::ifstream file_version("Config/VERSION", std::ios::binary);

        this->log.Debug("VERSION", "Load VERSION file.");

        file_version >> this->Version_out;

        file_version.close();
    }

        sf::Text mouseText;
        mouseText.setPosition(0, static_cast<float>(this->window->getSize().y - 20));
        mouseText.setFont(this->font);
        mouseText.setCharacterSize(12);
        mouseText.setFillColor(sf::Color::Black);
        std::stringstream ss;
        ss << "Ver. " << this->Version_out;
        mouseText.setString(ss.str());

    target->draw(mouseText);

    //!               .
    //! REMOVE LATER /!\
    //! ¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯
}

void MainMenuState::renderButton(sf::RenderTarget* target) {

    if(!target)
        target = this->window;

    for(auto &it : this->buttons) {

        it.second->render(target);
    }
}