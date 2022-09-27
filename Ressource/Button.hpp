#ifndef __RESSOURCE_BUTTON_HPP__
#define __RESSOURCE_BUTTON_HPP__

#include <iostream>
#include <ctime>
#include <cstdlib>
#include <sstream>
#include <array>

#include <SFML/System.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>

enum button_states {
    BTN_IDLE = 0,
    BTN_HOVER,
    BTN_PRESSED
};

class Button {

    public:

        Button(std::array<float,2> position, std::array<float,2> size, std::string text, sf::Font *font, sf::Color idleColor = sf::Color::White, sf::Color hoverColor = sf::Color::Magenta, sf::Color activeColor = sf::Color::Black);
        ~Button();
       
        void update(const sf::Vector2f mousePos);
        void render(sf::RenderTarget *target);

        const bool isPressed() const;
        const bool isHover() const;
    
    private:

        sf::RectangleShape shape;
        sf::Font *font;
        sf::Text text;

        sf::Color idleColor;
        sf::Color hoverColor;
        sf::Color activeColor;

        short unsigned buttonState;
};

#endif //! __RESSOURCE_BUTTON_HPP__