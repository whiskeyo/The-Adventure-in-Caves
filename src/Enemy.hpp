#ifndef ENEMY_HPP
#define ENEMY_HPP

#include "Collider.hpp"
#include "ICharacter.hpp"
#include "Settings.hpp"

#include <SFML/Graphics.hpp>

class Enemy : public ICharacter
{
public:
    Enemy(int l_type, sf::Vector2f l_position, int l_damage, int l_health);
    ~Enemy();

    void setAction(Action l_action);
    Action getAction();
    int getHealth();
    void changeHealth(int l_value);

    sf::Clock m_attack_clock;
    void attack(ICharacter* l_enemy);
    bool canAttack();

    sf::Vector2f getPosition();
    sf::Vector2f getHalfSize();
    Collider getCollider();

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
