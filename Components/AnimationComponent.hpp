#ifndef __COMPONENT_ANIMATIONCOMPONENT_HPP__
#define __COMPONENT_ANIMATIONCOMPONENT_HPP__

#include <iostream>
#include <string>
#include <map>

#include <SFML/System.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Network.hpp>

class AnimationComponent {

    public:

        AnimationComponent(sf::Sprite &sprite, sf::Texture &texture_sheet);
        virtual ~AnimationComponent();

        //-------------------------------| FUNCTIONS

        void addAnimation(const std::string key);

        void startAnimation(const std::string animation);
        void pauseAnimation(const std::string animation);
        void resetAnimation(const std::string animation);
        void update(const float &dt);

    private:

        class Animation {

            public:

                Animation(sf::Sprite &sprite, sf::Texture &textureSheet, float animation_Timer, int start_x, int start_y, int end_x, int end_y, int width, int height);

                //-------------------------------| FUNCTIONS

                void update(const float &dt);
                void play();
                void stop();
                void reset();

                //-------------------------------| VARIABLES

                sf::Sprite &sprite;
                sf::Texture &textureSheet;
                float animationTimer;
                float timer;
                int width;
                int height;
                sf::IntRect startRect;
                sf::IntRect currentRect;
                sf::IntRect endRect;

        };

        sf::Sprite &sprite;
        sf::Texture textureSheet;
        std::map<std::string, Animation> animations;

};

#endif //! __COMPONENT_ANIMATIONCOMPONENT_HPP__