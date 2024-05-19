#ifndef ENEMY_HPP
#define ENEMY_HPP

#include "Character.hpp"
#include "Collider.hpp"
#include "ResourceManager.hpp"
#include "Settings.hpp"

#include <SFML/Graphics.hpp>
#include <fstream>
#include <string>

class Enemy : public Character
{
public:
    Enemy(int l_type, sf::Vector2f l_position, int l_damage, int l_health);
    ~Enemy();

    void setAction(Action l_action)
    {
        m_action = l_action;
    }
    Action getAction()
    {
        return m_action;
    }
    int getHealth()
    {
        return m_health;
    }
    void changeHealth(int l_value)
    {
        m_health += l_value;
    }

    sf::Clock m_attack_clock;
    void attack(Character* l_enemy);
    bool canAttack()
    {
        return m_attack_clock.getElapsedTime() > sf::milliseconds(700);
    }

    sf::Vector2f getPosition()
    {
        return m_bounding_box.getPosition();
    }
    sf::Vector2f getHalfSize()
    {
        return sf::Vector2f(20, 28);
    }
    Collider getCollider()
    {
        return Collider(m_bounding_box);
    }

    void animation(int l_frames, int l_ms, int l_starting_x, int l_starting_y);
    void update();
    void render(sf::RenderWindow& l_window);

private:
    sf::RectangleShape m_bounding_box;
    int m_bounding_box_offset;
    Action m_action;
    int m_health;
    int m_damage;

    short int m_frame;
    sf::Clock m_anim_clock;
    sf::Sprite m_enemy_sprite;
};

#endif
