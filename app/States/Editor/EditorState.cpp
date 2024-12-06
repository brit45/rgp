#include "EditorState.hpp"

//----------------------------------------------| CONSTANTES

#define DELAY_PRESS_KEYS 300
#define MAX_INDEX 3

sf::Color base(137, 61, 51);
sf::Color primary(137, 161, 51);
sf::Color secondary(137, 161, 151);

//----------------------------------------------| END CONSTANTES

//-------------------------------| INITIALIZER

void EditorState::InitVariables() {


    //----------------------------------------------------------------------| PATHS

    this->path = new PathComponent(this->log);

    this->path->AddPath(GIRL_1, "assets/Images/Sprites/Player/girl1_1.png");
    this->path->AddPath(GIRL_1, "assets/Images/Sprites/Player/girl1_2.png");
    this->path->AddPath(GIRL_1, "assets/Images/Sprites/Player/girl1_3.png");
    this->path->AddPath(GIRL_1, "assets/Images/Sprites/Player/girl1_4.png");

    this->path->AddPath(GIRL_2, "assets/Images/Sprites/Player/girl2_1.png");
    this->path->AddPath(GIRL_2, "assets/Images/Sprites/Player/girl2_2.png");
    this->path->AddPath(GIRL_2, "assets/Images/Sprites/Player/girl2_3.png");
    this->path->AddPath(GIRL_2, "assets/Images/Sprites/Player/girl2_4.png");

    this->path->AddPath(BACKGROUND, "assets/Images/Backgrounds/bg1_girl1.png");
    this->path->AddPath(BACKGROUND, "assets/Images/Backgrounds/bg2_girl1.png");
    this->path->AddPath(BACKGROUND, "assets/Images/Backgrounds/bg3_girl1.png");

    this->path->AddPath(FONT, "assets/Fonts/manga.otf");

    this->path->AddPath(SOUND, "assets/Sounds/close.ogg");  // 0
    this->path->AddPath(SOUND, "assets/Sounds/paper.ogg");  // 1
    this->path->AddPath(SOUND, "assets/Sounds/sunset.ogg"); // 2

    this->path->AddPath(ASSETS, "assets/Images/3D/cat/Cat_v1_l3.obj");
    this->path->AddPath(ASSETS, "assets/Images/3D/test/test.obj");

    //----------------------------------------------------------------------| SOUND

    
    this->SoundMap["close"]  = new SoundComponent(this->path->GetPath(SOUND, CLOSE), SoundComponent::SOUND, this->log);
    this->SoundMap["paper"]  = new SoundComponent(this->path->GetPath(SOUND, PAPER), SoundComponent::SOUND, this->log);
    this->SoundMap["sunset"] = new SoundComponent(this->path->GetPath(SOUND, SUNSET), SoundComponent::MUSIC, this->log);

    this->SoundMap["sunset"]->Loop(true);
    this->SoundMap["sunset"]->Play();
    this->SoundMap["sunset"]->setVolume(50);

    this->SoundMap["paper"]->setVolume(1.70);

    this->SoundMap["close"]->setVolume(1.75);
    this->SoundMap["close"]->Play();

    //----------------------------------------------------------------------| PLAYER ASSETS


    this->persoOffset = GIRL_1;

    std::vector<std::string> p;
    for(int i(0); i < this->path->GetSize(GIRL_1); i++) {

        p.push_back(this->path->GetPath(GIRL_1, i));
    }

    this->girl_1 = new Girl(250, 0, this->window, p);
    this->girl_1->Show();

    p.clear();

    for (int i(0); i < this->path->GetSize(GIRL_2); i++)
    {

        p.push_back(this->path->GetPath(GIRL_2, i));
    }
    this->girl_2 = new Girl(30, 0, this->window, p);

    // this->obj3d.loadFromFile(this->path->GetPath(ASSETS,1)); ##! Ne functionne pas
}

void EditorState::InitBackground() {

    this->background.setSize(sf::Vector2f(static_cast<float>(this->window->getSize().x), static_cast<float>(this->window->getSize().y)));

    this->perso.setSize(sf::Vector2f(static_cast<float>(this->window->getSize().x), static_cast<float>(this->window->getSize().y)));

    this->setTexture(this->path->GetPath(BACKGROUND, this->index - 1), backgroundTexture, background);

    this->setTexture(this->path->GetPath(GIRL_1), persoTexture, perso);
}

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

    if(!this->font.loadFromFile(this->path->GetPath(FONT))) {

        this->log->Error("FONTS", "ERROR::EditorState → [ COULD NOT FOUND FONT ]");
        return;
    }

    this->log->Info("FONTS", "Load Font \"" + this->path->GetPath(FONT) + "\"");
}

void EditorState::setText() {}

void EditorState::setTexture(std::string path, sf::Texture &texture, sf::RectangleShape &shape) {

    if (!texture.loadFromFile(path))
    {

        this->log->Error("EditorState", "COULD NOT FOUND BACKGROUND IMAGE RESSOURCE");

        this->getQuit();
        return;
    }

    shape.setTexture(&texture);
}

//-------------------------------| CONSTRUCTOR / DESTRUCTOR

EditorState::EditorState(sf::RenderWindow *window, std::map<std::string, int> *supportesKeys, std::stack<State *> *states, Logger *log) : 
    State(window, supportesKeys, states, log) {

    this->log->Info("VIEWS", "⇨ Open view ` EditorState `.");

    this->InitVariables();
    this->InitBackground();
    this->InitFont();
    this->InitKeyBinds();
    this->setText();
}

EditorState::~EditorState() {

    for(auto it : this->SoundMap) {

        delete it.second;
    }

    delete this->path;

    delete this->girl_1;
    delete this->girl_2;

    this->log->Info("VIEWS", "⇦ Close view of ` EditorState `");
}

//-------------------------------| FUNCTIONS

sf::Clock timerKeys;

void EditorState::updateInput(const float &dt) {

    if(sf::Keyboard::isKeyPressed((sf::Keyboard::Key) this->keybinds.at("QUIT"))) {
        
        this->SoundMap["close"]->Play();

        while (this->SoundMap["close"]->isPlay()) {}

        this->endState();
    }

    if (sf::Keyboard::isKeyPressed((sf::Keyboard::Key)this->keybinds.at("RIGHT")) && timerKeys.getElapsedTime().asMilliseconds() > DELAY_PRESS_KEYS) {
        
        if ((this->index + 1) <= MAX_INDEX) {

            this->SoundMap["paper"]->Play();

            this->index++;
            this->setTexture(this->path->GetPath(BACKGROUND,index -1), this->backgroundTexture, this->background);
            
            timerKeys.restart();
        }

        
    }

    if (sf::Keyboard::isKeyPressed((sf::Keyboard::Key)this->keybinds.at("LEFT")) && timerKeys.getElapsedTime().asMilliseconds() > DELAY_PRESS_KEYS) {

        if ((this->index - 1) >= 1)
        {

            this->SoundMap["paper"]->Play();

            this->index--;

            this->setTexture(this->path->GetPath(BACKGROUND, index -1), this->backgroundTexture, this->background);

            timerKeys.restart();

        }
    }

    if (sf::Keyboard::isKeyPressed((sf::Keyboard::Key)this->keybinds.at("UP")) && timerKeys.getElapsedTime().asMilliseconds() > DELAY_PRESS_KEYS) {

        if (indexPerso + 1 < this->path->GetSize(this->persoOffset) + 1) {


            this->SoundMap["paper"]->Play();

            indexPerso++;

            this->setTexture(this->path->GetPath(this->persoOffset, indexPerso - 1), this->persoTexture, this->perso);

            timerKeys.restart();
        }

    }

    if (sf::Keyboard::isKeyPressed((sf::Keyboard::Key)this->keybinds.at("DOWN")) && timerKeys.getElapsedTime().asMilliseconds() > DELAY_PRESS_KEYS) {

        if (indexPerso - 1 >= 1) {


            this->SoundMap["paper"]->Play();

            indexPerso--;

            this->setTexture(this->path->GetPath(this->persoOffset, indexPerso - 1), this->persoTexture, this->perso);

            timerKeys.restart();
        }

    }

    if (sf::Keyboard::isKeyPressed((sf::Keyboard::Key)this->keybinds.at("D")) && timerKeys.getElapsedTime().asMilliseconds() > DELAY_PRESS_KEYS) {

        this->indexPerso = 1;
        this->index = 0;

        if(this->persoOffset == GIRL_1) {
            
            this->persoOffset = GIRL_2;
            this->girl_1->Hidden();
            this->girl_2->Show();
        }
        else {
        
            this->persoOffset = GIRL_1;
            this->girl_2->Hidden();
            this->girl_1->Show();
        }


        this->setTexture(this->path->GetPath(this->persoOffset, indexPerso - 1), this->persoTexture, this->perso);

        timerKeys.restart();
    }

    this->contentComponent.Clear();
}


void EditorState::update(const float &dt) {
    
    this->updateMousePositions();
    this->updateInput(dt);

    this->girl_1->update(dt);
    this->girl_1->Image(this->indexPerso -1);
    
    this->girl_2->update(dt);
    this->girl_2->Image(this->indexPerso -1);
}

void EditorState::render(sf::RenderTarget *target) {

    if (!target) {

        target = this->window;
    }

    if(this->persoOffset == GIRL_1)
        target->draw(this->background);


    if(this->girl_1->IsShow())
        this->girl_1->render(target);
    
    if (this->girl_2->IsShow())
        this->girl_2->render(target);
}
