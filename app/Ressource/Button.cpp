#include "Button.hpp"

Button::Button(std::array<float,2> position,std::array<float,2> size, std::string text, sf::Font *font, sf::Color idleColor, sf::Color hoverColor, sf::Color activeColor) {

    this->shape.setSize(sf::Vector2f(size[0], size[1]));
    this->shape.setPosition(sf::Vector2f(position[0], position[1]));

    this->buttonState = BTN_IDLE;

    this->font = font;
    this->text.setFont(*this->font);
    this->text.setString(text);
    this->text.setFillColor(sf::Color::White);
    this->text.setCharacterSize(16);

    this->text.setOrigin(

        this->text.getGlobalBounds().width / 2.f,
        this->text.getGlobalBounds().height / 2.f
    );

    this->text.setPosition(

        this->shape.getPosition().x + this->shape.getGlobalBounds().width / 2.f,
        this->shape.getPosition().y + this->shape.getGlobalBounds().height / 2.f
    );

    this->activeColor = activeColor;
    this->hoverColor  = hoverColor;
    this->idleColor   = idleColor;

    this->shape.setFillColor(this->idleColor);
}

Button::~Button() {}

void Button::render(sf::RenderTarget *target) {

    target->draw(this->shape);
    target->draw(this->text);
}

void Button::update(const sf::Vector2f mousePos) {

    this->buttonState = BTN_IDLE;

    if(this->shape.getGlobalBounds().contains(mousePos)) {

        this->buttonState = BTN_HOVER;

        if(sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
            
            this->buttonState = BTN_PRESSED;
        }

    }

    switch(this->buttonState) {

        case BTN_IDLE : {

            this->shape.setFillColor(this->idleColor);
        } break;

        case BTN_HOVER : {

            this->shape.setFillColor(this->hoverColor);
        } break;

        case BTN_PRESSED : {

            this->shape.setFillColor(this->activeColor);
        } break;

        default : {

            this->shape.setFillColor(sf::Color::Red);   
        } break;
    }
}

const bool Button::isPressed() const {

    return (this->buttonState == BTN_PRESSED) ? true : false;
}

const bool Button::isHover() const {
    
    return (this->buttonState == BTN_HOVER) ? true : false;
}