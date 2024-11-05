#ifndef __COMPONENENT_SOUND_HPP__
#define __COMPONENENT_SOUND_HPP__

#include "Component.inl"

class SoundComponent {

    public:

        SoundComponent(std::string filename, uint type_sound, Logger *logger);
        virtual ~SoundComponent();

        void Play();

        void Stop();

        void Loop(bool state);

        bool isPlay();

        void setVolume(float volume);

        enum Type {

            // Effects
            SOUND,

            // Music
            MUSIC
        };

    private:

        uint sound_type = Type::MUSIC;

        sf::Music music;
        sf::Sound sound;
        sf::SoundBuffer soundBuffer;

        std::string path;

        Logger *logger;
};

#endif //! __COMPONENENT_SOUND_HPP__
