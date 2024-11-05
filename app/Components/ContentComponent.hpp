#ifndef __COMPONENT_CONTENT_HPP__
#define __COMPONENT_CONTENT_HPP__

#include "Component.inl"
#include <map>

class ContentComponent {

    public:

        ContentComponent();
        virtual ~ContentComponent();

        void Render(sf::RenderTarget &target);

        void setText(std::string key, std::string text, sf::Vector2f position);
    
        void InitFont(std::string path, uint policeSize, sf::Color color);

        void InitFont(sf::Font &font, uint policeSize, sf::Color color);

        sf::Text &Set(std::string key);

        void Clear();
    
    private:

        sf::Font font;
        std::map<std::string, sf::Text*> Text;

};

#endif //! __COMPONENT_CONTENT_HPP__