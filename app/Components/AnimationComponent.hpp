#ifndef __COMPONENT_ANIMATIONCOMPONENT_HPP__
#define __COMPONENT_ANIMATIONCOMPONENT_HPP__

#include "Component.inl"

class AnimationComponent {

    public:

        AnimationComponent(sf::Sprite &sprite, sf::Texture &texture_sheet);
        virtual ~AnimationComponent();

        //-------------------------------| FUNCTIONS

        void addAnimation(const std::string key, float animation_Timer, int start_frame_x, int start_frame_y, int frame_x, int frame_y, int width, int height);
        void play(const std::string key, const float &dt);

    private:

        class Animation {

            public:

                Animation(sf::Sprite &sprite, sf::Texture &textureSheet, float animation_Timer, int start_x, int start_y, int end_x, int end_y, int width, int height);

                //-------------------------------| FUNCTIONS

                void play(const float &dt);;
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
        std::map<std::string, Animation*> animations;
        Animation *lastAnimation;

};

#endif //! __COMPONENT_ANIMATIONCOMPONENT_HPP__