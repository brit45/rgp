#include "Game.hpp"

//-------------------------------| STATIC FUNCTIONS

//-------------------------------| INITIALIZER FUNCTIONS

void Game::InitWindow() {

    std::ifstream ifs("Config/window.ini");

    std::string title = "None";
    sf::VideoMode window_bounds(800,600);
    unsigned framerate_limit = 120;
    bool vertical_sync_enabled = false;

    if(ifs.is_open()) {

        std::getline(ifs, title);
        ifs >> window_bounds.width >> window_bounds.height;
        ifs >> framerate_limit;
        ifs >> vertical_sync_enabled;

    }
    else {

        std::ofstream ofs("Config/window.ini");
        
        ofs << title << std::endl;
        ofs << window_bounds.width << " " << window_bounds.height << std::endl;
        ofs << framerate_limit << std::endl;
        ofs << vertical_sync_enabled;
        

        ofs.close();
    }

    ifs.close();
    
    this->window = new sf::RenderWindow(window_bounds,title);
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