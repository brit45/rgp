#include "AppearanceComponent.hpp"
#include <random>

// Constructeur
AppearanceComponent::AppearanceComponent(sf::Sprite& sprite) : sprite(sprite) {}

// Destructeur
AppearanceComponent::~AppearanceComponent() {}

// Ajouter ou modifier une partie
void AppearanceComponent::setPart(const std::string& part, sf::Texture* texture, const sf::IntRect& rect, const sf::Color& color, bool visible) {
    this->layers[part] = AppearanceLayer(texture, rect, color, visible);
}

// Supprimer une partie
void AppearanceComponent::removePart(const std::string& part) {
    this->layers.erase(part);
}

// Activer ou désactiver une partie
void AppearanceComponent::setVisibility(const std::string& part, bool visible) {
    if (this->layers.find(part) != this->layers.end()) {
        this->layers[part].visible = visible;
    }
}

// Générer une apparence procédurale
void AppearanceComponent::generateAppearance(const std::map<std::string, std::vector<sf::Texture*>>& textureOptions,
                                              const std::map<std::string, std::vector<sf::Color>>& colorOptions) {
    std::random_device rd;
    std::mt19937 rng(rd());

    for (const auto& [part, textures] : textureOptions) {
        if (!textures.empty()) {
            std::uniform_int_distribution<size_t> textureDist(0, textures.size() - 1);
            sf::Texture* selectedTexture = textures[textureDist(rng)];

            sf::Color selectedColor = sf::Color::White; // Couleur par défaut
            if (colorOptions.find(part) != colorOptions.end() && !colorOptions.at(part).empty()) {
                const auto& colors = colorOptions.at(part);
                std::uniform_int_distribution<size_t> colorDist(0, colors.size() - 1);
                selectedColor = colors[colorDist(rng)];
            }

            this->setPart(part, selectedTexture, sf::IntRect(0, 0, selectedTexture->getSize().x, selectedTexture->getSize().y), selectedColor, true);
        }
    }
}

// Appliquer l'apparence
void AppearanceComponent::applyAppearance() {
    for (const auto& [part, layer] : this->layers) {
        if (layer.visible && layer.texture) {
            // Appliquer uniquement la texture de la base (optionnel selon logique finale)
            if (part == "tête") {  // Exemple pour une partie principale
                this->sprite.setTexture(*layer.texture);
                this->sprite.setTextureRect(layer.textureRect);
                this->sprite.setColor(layer.color);
            }
        }
    }
}
