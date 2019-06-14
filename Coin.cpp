#include "Coin.hpp"

Coin::Coin(sf::Vector2f l_position)
{
    m_frame = 0;
    m_anim_clock.restart();

    m_coin_sprite.setTexture(ResourceManager::getInstance()->requestTexture("coin"), true);
    m_coin_sprite.setTextureRect(sf::IntRect(sf::Vector2i(0, 0), C_FRAMESIZE));
    m_coin_sprite.setOrigin(100.0f, 100.0f);
    m_coin_sprite.scale(0.2f, 0.2f);
    m_coin_sprite.setPosition(l_position);

    m_bounding_box.setSize(sf::Vector2f(40, 40));
    m_bounding_box.setFillColor(G_COLLECTIBLE);
    m_bounding_box.setOrigin(20.0f, 20.0f);
    m_bounding_box.setPosition(l_position);
}

void Coin::animation(int l_frames, int l_ms, int l_starting_x, int l_starting_y)
{
    if (m_anim_clock.getElapsedTime() > sf::milliseconds(l_ms))
    {
        m_anim_clock.restart();
        if (m_frame <  l_frames)  m_frame++;
        if (m_frame == l_frames)  m_frame = 0;
        m_coin_sprite.setTextureRect(sf::IntRect(sf::Vector2i(l_starting_x * m_frame, l_starting_y), C_FRAMESIZE));
    }
}

void Coin::update()
{
    animation(6, 200, 200, 0);
}

void Coin::render(sf::RenderWindow& l_window)
{
    //l_window.draw(m_bounding_box);
    l_window.draw(m_coin_sprite);
}

