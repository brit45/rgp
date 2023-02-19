#ifndef __COMPONENTS_HITBOXCOMPONENT_HPP__
#define __COMPONENTS_HITBOXCOMPONENT_HPP__

#include "Component.inl"

class HitboxComponent {

    public:

        /**
         * @brief Construct a new Hitbox Component.
         * 
         * @param sprite 
         * @param offset_x 
         * @param offset_y 
         * @param width 
         * @param height 
         */
        HitboxComponent(sf::Sprite &sprite, float offset_x , float offset_y, float width, float height);
        
        virtual ~HitboxComponent();

        /**
         * @brief Check Collisions.
         * 
         * @param frect 
         * @return true 
         * @return false 
         */
        bool checkIntersect(const sf::FloatRect &frect);

        void update(const float &dt);

        /**
         * @brief Render View.
         * 
         * @param target 
         */
        void render(sf::RenderTarget &target);
    
    private:

    sf::RectangleShape hitbox;
    sf::Vector2f offset;
    sf::Sprite &sprite;
        
};

#endif //! __COMPONENTS_HITBOXCOMPONENT_HPP__