#include "Heart.hpp"

Heart::Heart(sf::Vector2f l_position)
{
    m_frame = 0;
    m_anim_clock.restart();
    m_heart_sprite.setTexture(ResourceManager::getInstance()->requestTexture("heart"), true);
    m_heart_sprite.setTextureRect(sf::IntRect(sf::Vector2i(0, 0), H_FRAMESIZE));
    m_heart_sprite.setOrigin(100, 100);
    m_heart_sprite.scale(0.2f, 0.2f);
    m_heart_sprite.setPosition(l_position);
    m_bounding_box.setSize(sf::Vector2f(40, 40));
    m_bounding_box.setFillColor(G_COLLECTIBLE);
    m_bounding_box.setOrigin(20, 20);
    m_bounding_box.setPosition(l_position);
}

void Heart::animation(int l_frames, int l_ms, int l_starting_x, int l_starting_y)
{
    if (m_anim_clock.getElapsedTime() > sf::milliseconds(l_ms))
    {
        m_anim_clock.restart();
        if (m_frame < l_frames)
            m_frame++;
        if (m_frame == l_frames)
            m_frame = 0;
        m_heart_sprite.setTextureRect(sf::IntRect(sf::Vector2i(l_starting_x * m_frame, l_starting_y), H_FRAMESIZE));
    }
}

void Heart::update()
{
    animation(5, 240, 200, 0);
}

void Heart::render(sf::RenderWindow& l_window)
{
    // l_window.draw(m_bounding_box);
    l_window.draw(m_heart_sprite);
}
