#ifndef HEART_HPP
#define HEART_HPP

#include "Collider.hpp"
#include "ICollectible.hpp"
#include "Settings.hpp"

#include <SFML/Graphics.hpp>

class Heart : ICollectible
{
public:
    Heart(sf::Vector2f l_position);

    Collider getCollider();

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
