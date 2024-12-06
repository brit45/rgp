#ifndef __COMPONENT_APPEARANCECOMPONENT_HPP__
#define __COMPONENT_APPEARANCECOMPONENT_HPP__

#include <SFML/Graphics.hpp>
#include <map>
#include <string>
#include <vector>

class AppearanceComponent {
public:
    struct AppearanceLayer {
        sf::Texture* texture;  // Texture pour la couche
        sf::IntRect textureRect;  // Zone utilisée dans la texture
        sf::Color color;  // Couleur pour teinter cette couche
        bool visible;  // Indique si la couche est activée ou non

        AppearanceLayer(sf::Texture* texture = nullptr, const sf::IntRect& rect = sf::IntRect(), 
                        const sf::Color& color = sf::Color::White, bool visible = true)
            : texture(texture), textureRect(rect), color(color), visible(visible) {}
    };

    AppearanceComponent(sf::Sprite& sprite);
    virtual ~AppearanceComponent();

    //-------------------------------| FUNCTIONS

    // Ajouter ou modifier une partie
    void setPart(const std::string& part, sf::Texture* texture, const sf::IntRect& rect,
                 const sf::Color& color = sf::Color::White, bool visible = true);

    // Supprimer une partie
    void removePart(const std::string& part);

    // Activer ou désactiver une partie
    void setVisibility(const std::string& part, bool visible);

    // Génération procédurale de l'apparence
    void generateAppearance(const std::map<std::string, std::vector<sf::Texture*>>& textureOptions,
                            const std::map<std::string, std::vector<sf::Color>>& colorOptions);

    // Appliquer l'apparence au sprite
    void applyAppearance();

private:
    sf::Sprite& sprite;  // Le sprite auquel l'apparence est appliquée
    std::map<std::string, AppearanceLayer> layers;  // Toutes les couches d'apparence
};

#endif //! __COMPONENT_APPEARANCECOMPONENT_HPP__
