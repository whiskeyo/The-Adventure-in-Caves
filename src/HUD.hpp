#ifndef HUD_HPP
#define HUD_HPP

#include "HealthBar.hpp"
#include "Player.hpp"
#include "Settings.hpp"

#include <SFML/Graphics.hpp>
#include <list>

class HUD
{
public:
    HUD(Player* l_player);

    void update();
    void render(sf::RenderWindow& l_window);

    std::list<HealthBar> m_health;

private:
    Player* m_player;

    sf::Vector2f m_health_pos;
    sf::Text m_score_text;
    sf::Text m_score_record_text;
};

#endif // HUD_HPP
