#ifndef HUD_HPP
#define HUD_HPP

#include "Constants.hpp"
#include "Player.hpp"

#include <SFML/Graphics.hpp>
#include <iostream>
#include <list>
#include <vector>

struct HeartHUD
{
    HeartHUD(sf::Vector2f l_position)
    {
        m_heart_sprite.setTexture(ResourceManager::getInstance()->requestTexture("heart"), true);
        m_heart_sprite.setTextureRect(sf::IntRect(sf::Vector2i(0, 0), H_FRAMESIZE));
        m_heart_sprite.scale(0.2f, 0.2f);
        m_heart_sprite.setPosition(l_position);
    }

    void render(sf::RenderWindow& l_window)
    {
        l_window.draw(m_heart_sprite);
    }

    sf::Sprite m_heart_sprite;
};

class HUD
{
public:
    HUD(taic::Player* l_player);

    void update();
    void render(sf::RenderWindow& l_window);

    std::list<HeartHUD> m_health;

private:
    taic::Player* m_player;

    sf::Vector2f m_health_pos;
    sf::Text m_score_text;
    sf::Text m_score_record_text;
};

#endif // HUD_HPP
