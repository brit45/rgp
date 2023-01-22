#include "Game.hpp"

//-------------------------------| STATIC FUNCTIONS

//-------------------------------| INITIALIZER FUNCTIONS

void Game::InitVariables() {
    
    this->window        = NULL;
    this->fullscreen    = false;
    this->dt            = 0.f;
}

void Game::InitWindow() {

    std::ifstream ifs("Config/window.ini");

    this->videoModes = sf::VideoMode::getFullscreenModes();
    std::string title = "None";
    sf::VideoMode window_bounds = sf::VideoMode::getDesktopMode();

    unsigned framerate_limit = 120;
    bool vertical_sync_enabled = false;

    unsigned antialiasing_level = 0;


    if(ifs.is_open()) {

        std::string param = "";

        while(ifs >> param) {

            if(param == "title") {
                
                std::getline(ifs, title);
            }
            if(param == "windows_size") {
                
                ifs >> window_bounds.width >> window_bounds.height;
            }
            if(param == "frame_limit") {
                
                ifs >> framerate_limit;
            }
            if(param == "vertical_sync") {
                
                ifs >> vertical_sync_enabled;
            }
            if(param == "fullscreen") {
                
                ifs >> this->fullscreen;
            }
            if(param == "antialias_level") {
                
                ifs >> antialiasing_level;
            }
            if(param.substr(0,1) == "#" || param.substr(0,1) == ";") {
                
                continue;
            }
        }

    }
    else {

        std::ofstream ofs("Config/window.ini");
        
        ofs << "title\t\t" << title << std::endl;
        ofs << "windows_size\t\t" << window_bounds.width << " " << window_bounds.height << std::endl;
        ofs << "frame_limit\t\t" << framerate_limit << std::endl;
        ofs << "vertical_sync\t\t" << vertical_sync_enabled << std::endl;
        ofs << "fullscreen\t\t" << this->fullscreen << std::endl;
        ofs << "antialias_level\t\t" << antialiasing_level;

        ofs.close();
    }

    ifs.close();
    
    this->windowSettings.antialiasingLevel = antialiasing_level;

    if(this->fullscreen)
        this->window = new sf::RenderWindow(window_bounds,title, sf::Style::Fullscreen , this->windowSettings);
    else
        this->window = new sf::RenderWindow(window_bounds,title, sf::Style::Titlebar | sf::Style::Close, this->windowSettings);

    this->window->setFramerateLimit(framerate_limit);
    this->window->setVerticalSyncEnabled(vertical_sync_enabled);
}

void Game::InitStates() {
    
    this->states.push(new MainMenuState(this->window, &this->supportedKeys, &this->states));
}

void Game::InitKeys() {

    std::ifstream ifs("Config/supported_Key.ini");

    if(ifs.is_open()) {
        
        std::string key = "";
        int key_value = 0;

        while(ifs >> key >> key_value) {

            this->supportedKeys[key] = key_value;
        }
    }
    else {

        this->supportedKeys["Up"]       = sf::Keyboard::Key::Up;
        this->supportedKeys["Left"]     = sf::Keyboard::Key::Left;
        this->supportedKeys["Right"]    = sf::Keyboard::Key::Right;
        this->supportedKeys["Down"]     = sf::Keyboard::Key::Down;
        this->supportedKeys["Esc"]      = sf::Keyboard::Key::Escape;

        std::ofstream ofs("Config/supported_Key.ini");

        for(auto i : this->supportedKeys) {

            ofs << i.first << " " << i.second << std::endl;
        }

        ofs.close();
    }

    ifs.close();    
}

//-------------------------------| CONSTRUCTOR / DESTRUCTOR

Game::Game() {

    this->InitKeys();
    this->InitVariables();
    this->InitWindow();
    this->InitStates();
}

Game::~Game() {

    delete this->window;

    while(!this->states.empty()) {

        delete this->states.top();
        this->states.pop();
    }
}

//-------------------------------| FUNCTIONS

void Game::endApplication() {

    this->window->close();
}

void Game::updateSFMLEvents() {

    while(this->window->pollEvent(this->sfEvent)) {
    
        if(this->sfEvent.type == sf::Event::Closed) this->window->close();
    }
}

void Game::update() {

    this->updateSFMLEvents();
    
    if(!this->states.empty()) {

        this->states.top()->update(this->dt);

        if(this->states.top()->getQuit()) {

            this->states.top()->endState();
            
            delete this->states.top();
            this->states.pop();
        }
    }
    else {

        this->endApplication();
    }
}

void Game::updateDt() {

    this->dt = this->dtClock.restart().asSeconds();

}

void Game::render() {

    this->window->clear();
    
    //-------------------------------| RENDER ITEMS
    
    if(!this->states.empty()) {

        this->states.top()->render();
    }

    this->window->display();
}

void Game::run() {

    while(this->window->isOpen()) {

        this->updateDt();
        this->update();
        this->render();
    }
}