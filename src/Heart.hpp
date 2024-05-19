#ifndef HEART_HPP
#define HEART_HPP

#include "Collectible.hpp"
#include "Collider.hpp"
#include "ResourceManager.hpp"
#include "Settings.hpp"

#include <SFML/Graphics.hpp>

class Heart : Collectible
{
public:
    Heart(sf::Vector2f l_position);

    Collider getCollider()
    {
        return Collider(m_bounding_box);
    }
    void animation(int l_frames, int l_ms, int l_starting_x, int l_starting_y);
    void update();
    void render(sf::RenderWindow& l_window);

private:
    sf::RectangleShape m_bounding_box;
    short int m_frame;
    sf::Clock m_anim_clock;
    sf::Sprite m_heart_sprite;
};
#endif // HEART_HPP
