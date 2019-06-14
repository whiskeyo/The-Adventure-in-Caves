#include "Enemy.hpp"

Enemy::Enemy(int l_type, sf::Vector2f l_position, int l_damage, int l_health)
{
    m_action = Action::NONE;
    m_frame = 0;
    m_damage = l_damage;
    m_health = l_health;
    m_anim_clock.restart();
    m_attack_clock.restart();
    m_bounding_box.setSize(sf::Vector2f(30, 56));
    m_bounding_box.setOrigin(sf::Vector2f(15, 28));
    m_bounding_box.setFillColor(sf::Color(255, 0, 255, 100));

    switch (l_type)
    {
        case 6: m_enemy_sprite.setTexture(ResourceManager::getInstance()->requestTexture("enemy_weak_left"), true);
                m_bounding_box_offset = -15;
                break;
        case 7: m_enemy_sprite.setTexture(ResourceManager::getInstance()->requestTexture("enemy_weak_right"), true);
                m_bounding_box_offset = 15;
                break;
        case 8: m_enemy_sprite.setTexture(ResourceManager::getInstance()->requestTexture("enemy_strong_left"), true);
                m_bounding_box_offset = -15;
                break;
        case 9: m_enemy_sprite.setTexture(ResourceManager::getInstance()->requestTexture("enemy_strong_right"), true);
                m_bounding_box_offset = 15;
                break;
       default: break;
    }

    m_enemy_sprite.setPosition(sf::Vector2f(l_position.x, l_position.y + 4));
    //m_bounding_box.setPosition(l_position);
    m_enemy_sprite.setOrigin(E_FRAMESIZE2);
    m_enemy_sprite.setTextureRect(sf::IntRect(sf::Vector2i(512, 0), E_FRAMESIZE));
    //m_enemy_sprite.setPosition(sf::Vector2f(l_position.x, l_position.y + 4));
    //m_bounding_box.setPosition(m_enemy_sprite.getPosition());
}

Enemy::~Enemy() {}

void Enemy::attack(Character *l_enemy)
{
    l_enemy->changeHealth(-m_damage);
    m_attack_clock.restart();
}

void Enemy::animation(int l_frames, int l_ms, int l_starting_x, int l_starting_y)
{
    if (m_anim_clock.getElapsedTime() > sf::milliseconds(l_ms))
    {
        m_anim_clock.restart();
        if (m_frame <  l_frames)  m_frame++;
        if (m_frame == l_frames)  m_frame = 0;
        m_enemy_sprite.setTextureRect(sf::IntRect(sf::Vector2i(l_starting_x + 64 * m_frame, l_starting_y), E_FRAMESIZE));
    }
}

void Enemy::update()
{
    if (m_action == Action::NONE)
        animation(8, 250, 512, 0);
        //m_enemy_sprite.setTextureRect(sf::IntRect(sf::Vector2i(512, 0), E_FRAMESIZE));
    if (m_action == Action::ATTACKING)
        animation(8, 60, 0, 0);

    m_bounding_box.setPosition(m_enemy_sprite.getPosition().x + m_bounding_box_offset,
                               m_enemy_sprite.getPosition().y);
}

void Enemy::render(sf::RenderWindow& l_window)
{
    //l_window.draw(m_bounding_box);
    l_window.draw(m_enemy_sprite);
}
