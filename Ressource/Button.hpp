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

        /**
         * @brief Construct a new Button object
         * 
         * @param position Position on screen.
         * @param size Size of button.
         * @param text Text label in button.
         * @param font Font of text.
         * @param idleColor Color by default if button is enable.
         * @param hoverColor Color of button if mouse pointer is hover.
         * @param activeColor Color of button if is enable.
         */
        Button(std::array<float,2> position, std::array<float,2> size, std::string text, sf::Font *font, sf::Color idleColor = sf::Color::White, sf::Color hoverColor = sf::Color::Magenta, sf::Color activeColor = sf::Color::Black);
        ~Button();

        /**
         * @brief Update info of button.
         * 
         * @param mousePos Position of mouse pointer.
         */
        void update(const sf::Vector2f mousePos);

        /**
         * @brief Show button on global application.
         * 
         * @param target Draw button in global application.
         */
        void render(sf::RenderTarget *target);
        
        /**
         * @brief Detect if button is clicked.
         * 
         * @return true 
         * @return false 
         */
        const bool isPressed() const;

        /**
         * @brief Detect if mouse pointer is hover the button.
         * 
         * @return true 
         * @return false 
         */
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