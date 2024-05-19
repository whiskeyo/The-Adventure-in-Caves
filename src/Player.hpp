#ifndef PLAYER_HPP
#define PLAYER_HPP

#include <fstream>
#include <string>
#include "World.hpp"
#include "ResourceManager.hpp"
#include "Settings.hpp"
#include "Character.hpp"
#include "Collider.hpp"
#include <SFML/Graphics.hpp>

class Player : public Character
{
    public:
        Player(std::string l_filename);

        void setPosition(sf::Vector2f l_position) { m_bounding_box.setPosition(l_position); }
        void setAction(Action l_action) { m_action = l_action; }
        void setSpeedX(float l_speed_x) { m_speed.x = l_speed_x; }
        void setSpeedY(float l_speed_y) { m_speed.y = l_speed_y; }

        void changeHealth(int l_value) { m_health += l_value; }
        void changeScore(int l_value) { m_score += l_value; }

        sf::Vector2f getSpeed() { return m_speed; }
        Action getAction() { return m_action; }
        int getHealth() { return m_health; }
        int getScore() { return m_score; }
        int getScoreRecord() { return m_score_record; }
        
        void attack(Character *l_enemy);
        bool canAttack() { return m_attack_clock.getElapsedTime() > sf::milliseconds(300); }

        sf::Vector2f getPosition() { return m_bounding_box.getPosition(); }
        sf::Vector2f getHalfSize() { return sf::Vector2f(20, 28); }
        sf::Vector2f m_collision_direction;
        Collider getCollider() { return Collider(m_bounding_box); }
        void onCollision(sf::Vector2f l_collision_direction);

        bool hasLost() { return m_lost; }
        void lose() { m_lost = true; }

        void gameOver();
        void restartGame();

        void animation(int l_frames, int l_ms, int l_starting_x, int l_starting_y);
        void update();
        void render(sf::RenderWindow& l_window);

    private:
        Action m_action;
        sf::RectangleShape m_bounding_box;

        sf::Vector2f m_starting_position;
        sf::Vector2f m_speed;
        sf::Vector2f m_accel;
        float m_jump_speed;
        int m_max_speed;
        bool m_can_jump;


        bool m_boost;
        bool m_lost;
        int m_damage;
        int m_health;
        int m_score;
        int m_score_record;
        sf::Clock m_attack_clock;

        short int m_frame;
        sf::Clock m_anim_clock;
        bool m_dying_anim_played;
        //sf::Clock m_dying_clock;
        sf::Sprite  m_player_sprite;
};


#endif
