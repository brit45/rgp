#include "SoundComponent.hpp"

SoundComponent::SoundComponent(std::string filename, uint type_sound, Logger *logger) {

    this->logger = logger;

    this->path = filename;

    this->sound_type = type_sound;

    if(sound_type == MUSIC) {

        if(!this->music.openFromFile(filename)) {

            logger->Error("MUSIC", "Cannot Find \""+filename+"\".");

            return;
        }
        else {

            logger->Info("MUSIC", "Load \"" + filename + "\".");
        }
    }
    
    else if (sound_type == SOUND) {

        if (!this->soundBuffer.loadFromFile(filename))
        {

            logger->Error("SOUND", "Cannot Find \"" + filename + "\".");

            return;
        }
        else
        {

            logger->Info("SOUND", "Load \"" + filename + "\".");
        }

        this->sound.setBuffer(this->soundBuffer);
    }
}

SoundComponent::~SoundComponent() {

    if (this->sound_type == MUSIC)
    {

        this->logger->Info("MUSIC","Remove \""+this->path+"\" of memory.");
    }

    else if (this->sound_type == SOUND)
    {

        this->logger->Info("SOUND","Remove \""+this->path+"\" of memory.");
    }
}

void SoundComponent::Play() {

    if(this->sound_type == MUSIC) {
        
        this->music.play();
    }
    
    else if(this->sound_type == SOUND) {

        this->sound.play();
    }
}

void SoundComponent::Stop() {

    if (this->sound_type == MUSIC)
    {

        this->music.stop();
    }
    
    else if (this->sound_type == SOUND)
    {

        this->sound.stop();
    }
}

void SoundComponent::Loop(bool state) {

    if (this->sound_type == MUSIC)
    {

        this->music.setLoop(state);
        
        if(state) {

            this->logger->Info("MUSIC", "Set Music state of \"" + this->path + "\":");
            this->logger->Info("MUSIC", "\t↳ Set: 'loop'");
        }
    }
    
    else if (this->sound_type == SOUND)
    {
        
        if(state) {
            this->logger->Info("SOUND", "Set Sound state of \"" + this->path + "\":");
            this->logger->Error("SOUND", "\t↳ Set 'loop' with 'SOUND' type is not allowed. (Use 'MUSIC' type for this).");
        }
    }
}

bool SoundComponent::isPlay() {

    if (this->sound_type == MUSIC)
    {

        if(this->music.getStatus() == sf::Music::Playing) {
            
            return true;
        }
    }
    
    else if (this->sound_type == SOUND)
    {

        if(this->sound.getStatus() == sf::Sound::Playing) {
            
            return true;
        }
    }

    return false;
}

void SoundComponent::setVolume(float volume) {

    if (this->sound_type == MUSIC)
    {

        this->music.setVolume(static_cast<float>(volume));
        this->logger->Info("MUSIC", "Set Music state of \"" + this->path + "\":");
        this->logger->Info("MUSIC", "\t↳ Set: 'volume' : " + std::to_string(volume));
    }

    else if (this->sound_type == SOUND)
    {

        this->sound.setVolume(static_cast<float>(volume));
        this->logger->Info("SOUND", "Set Sound state of \"" + this->path + "\":");
        this->logger->Info("SOUND", "\t↳ Set: 'volume' : " + std::to_string(volume));
    }
}
