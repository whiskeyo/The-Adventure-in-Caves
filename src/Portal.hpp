#ifndef PORTAL_HPP
#define PORTAL_HPP

#include "Collider.hpp"
#include "ICollectible.hpp"
#include "Settings.hpp"

#include <SFML/Graphics.hpp>

class Portal : ICollectible
{
public:
    Portal(sf::Vector2f l_position, int l_type);

    Collider getCollider()
    {
        return Collider(m_bounding_box);
    }

    sf::Clock m_portal_clock;
    bool canTeleport()
    {
        return m_portal_clock.getElapsedTime() > sf::milliseconds(700);
    }
    bool whichType()
    {
        return m_type;
    }

    void animation(int l_frames, int l_ms, int l_starting_x, int l_starting_y);
    void update();
    void render(sf::RenderWindow& l_window);

private:
    sf::RectangleShape m_bounding_box;
    int m_type;
    short int m_frame;
    sf::Clock m_anim_clock;
    sf::Sprite m_portal_sprite;
};

#endif // PORTAL_HPP
