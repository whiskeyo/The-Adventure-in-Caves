#include "Portal.hpp"

Portal::Portal(sf::Vector2f l_position, int l_type)
{
    m_frame = 0;
    m_anim_clock.restart();
    m_type = l_type;

    if (m_type == 0)
        m_portal_sprite.setTexture(ResourceManager::getInstance()->requestTexture("portal_bright"), true);
    if (m_type == 1)
        m_portal_sprite.setTexture(ResourceManager::getInstance()->requestTexture("portal_dark"), true);

    m_portal_sprite.setTextureRect(sf::IntRect(sf::Vector2i(0, 0), sf::Vector2i(120, 200)));
    m_portal_sprite.setOrigin(60.0f, 100.0f);
    m_portal_sprite.scale(0.4f, 0.4f);
    m_portal_sprite.setPosition(l_position);

    m_bounding_box.setSize(sf::Vector2f(52, 80));
    m_bounding_box.setFillColor(G_COLLECTIBLE);
    m_bounding_box.setOrigin(27.0f, 40.0f);
    m_bounding_box.setPosition(l_position);
}

void Portal::animation(int l_frames, int l_ms, int l_starting_x, int l_starting_y)
{
    if (m_anim_clock.getElapsedTime() > sf::milliseconds(l_ms))
    {
        m_anim_clock.restart();
        if (m_frame <  l_frames)  m_frame++;
        if (m_frame == l_frames)  m_frame = 0;
        m_portal_sprite.setTextureRect(sf::IntRect(sf::Vector2i(l_starting_x * m_frame, l_starting_y),
                                                   sf::Vector2i(120, 200)));
    }
}

void Portal::update()
{
    animation(6, 110, 120, 0);

    m_bounding_box.setPosition(m_portal_sprite.getPosition().x,
                               m_portal_sprite.getPosition().y);
}

void Portal::render(sf::RenderWindow& l_window)
{
    //l_window.draw(m_bounding_box);
    l_window.draw(m_portal_sprite);
}

