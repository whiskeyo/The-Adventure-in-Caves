#ifndef COIN_HPP
#define COIN_HPP

#include "Collider.hpp"
#include "ICollectible.hpp"
#include "Settings.hpp"

#include <SFML/Graphics.hpp>

class Coin : ICollectible
{
public:
    Coin(sf::Vector2f position);

    Collider getCollider();
    void animation(int l_frames, int l_ms, int l_starting_x, int l_starting_y);
    void update();
    void render(sf::RenderWindow& l_window);

private:
    sf::RectangleShape m_bounding_box;
    short int m_frame;
    sf::Clock m_anim_clock;
    sf::Sprite m_coin_sprite;
};
#endif // COIN_HPP
