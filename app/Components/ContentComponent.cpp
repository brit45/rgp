#include "ContentComponent.hpp"

ContentComponent::ContentComponent(){}

ContentComponent::~ContentComponent() {}

void ContentComponent::Render(sf::RenderTarget &target) {

    for(auto t : this->Text) {

        t.second->setFont(this->font);

        target.draw(*t.second);
    }
}

void ContentComponent::setText(std::string key, std::string text, sf::Vector2f position) {

    this->Text[key] = new sf::Text;

    this->Text[key]->setString(text);

    this->Text[key]->setPosition(position);
}

void ContentComponent::InitFont(std::string path, uint policeSize, sf::Color color) {

    this->font.loadFromFile(path);

    for(auto t : this->Text) {

        t.second->setFont(this->font);
        t.second->setCharacterSize(policeSize);
        t.second->setFillColor(color);
    }
}

void ContentComponent::InitFont(sf::Font &font, uint policeSize, sf::Color color)
{

    this->font = font;

    for (auto t : this->Text)
    {

        t.second->setFont(this->font);
        t.second->setCharacterSize(policeSize);
        t.second->setFillColor(color);
    }
}

sf::Text &ContentComponent::Set(std::string key) {

    return *this->Text[key];
}

void ContentComponent::Clear() {

    this->Text.clear();
}
