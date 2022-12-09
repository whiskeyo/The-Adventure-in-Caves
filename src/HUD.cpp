#include "HUD.hpp"

HUD::HUD(taic::Player* l_player) : m_player(l_player)
{
    m_health_pos.x = 50;
    m_health_pos.y = 855;

    m_score_text.setFont(ResourceManager::getInstance()->requestFont("hud"));
    m_score_text.setCharacterSize(40);
    m_score_text.setFillColor(sf::Color(255, 255, 255));
    m_score_text.setPosition(800, 852);

    m_score_record_text.setFont(ResourceManager::getInstance()->requestFont("hud"));
    m_score_record_text.setCharacterSize(40);
    m_score_record_text.setFillColor(sf::Color(255, 255, 255));
    m_score_record_text.setPosition(1200, 852);
}

void HUD::update()
{
    m_score_text.setString("Score: " + std::to_string(m_player->getScore()));
    m_score_record_text.setString("Record: " + std::to_string(m_player->getScoreRecord()));

    if (m_player->getHealth() == m_health.size())
    {
        return;
    }

    int hp_diff = abs(m_player->getHealth() - (int)m_health.size());

    if (m_player->getHealth() > (int)m_health.size())
    {
        for (int i = 0; i <= hp_diff && m_player->getHealth() > 0; i++)
        {
            m_health.push_back(HeartHUD(sf::Vector2f(m_health_pos.x + m_health.size() * 50, m_health_pos.y)));
        }
    }

    if (m_player->getHealth() < (int)m_health.size())
    {
        for (int i = 0; i < m_player->getHealth() - m_health.size(); i++)
        {
            m_health.pop_back();
        }
    }
}

void HUD::render(sf::RenderWindow& l_window)
{
    l_window.draw(m_score_text);
    l_window.draw(m_score_record_text);
    for (HeartHUD& heart : m_health)
    {
        heart.render(l_window);
    }
}
