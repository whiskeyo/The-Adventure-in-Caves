#include "Player.hpp"

#include "Constants.hpp"

namespace taic
{

Player::Player(std::string l_filename)
{
    m_action = Action::NONE;
    m_accel.x = 1.25;
    m_accel.y = 1.25; // gravity
    m_speed.x = 0;
    m_speed.y = 0;
    m_max_speed = 4;
    m_jump_speed = 23;
    m_damage = 1;
    m_health = 5;
    m_score = 0;
    m_score_record = 0;
    m_can_jump = true;
    m_boost = true;
    m_lost = false;

    m_attack_clock.restart();
    m_anim_clock.restart();

    m_bounding_box.setSize(constant::player::bounding_box_size);
    m_bounding_box.setOrigin(constant::player::bounding_box_origin);
    m_bounding_box.setFillColor(constant::player::bounding_box_color);

    m_frame = 0;
    // m_player_texture.loadFromFile(ResourceManager::getInstance()->requestTexture("player"));
    m_player_sprite.setTexture(ResourceManager::getInstance()->requestTexture("player"), true);
    m_player_sprite.setOrigin(constant::player::texture_origin);

    std::ifstream level;
    level.open(l_filename.c_str());

    for (int block_y = 0; block_y < 18; block_y++)
    {
        for (int block_x = 0; block_x < 32; block_x++)
        {
            int find_player;
            level >> find_player;
            if (find_player == 2)
            {
                m_bounding_box.setPosition(50 * block_x + 29, 50 * block_y + 22);
                m_starting_position = sf::Vector2f(50 * block_x + 29, 50 * block_y + 22);
            }
        }
    }

    level.close();
}

void Player::attack(Character* l_enemy)
{
    l_enemy->changeHealth(-m_damage);
    m_attack_clock.restart();
}

void Player::onCollision(sf::Vector2f l_collision_direction)
{
    if (l_collision_direction.x < 0.0f)
    { // collision on the left
        m_speed.x = 0.0f;
    }
    else if (l_collision_direction.x > 0.0f)
    { // collision on the right
        m_speed.x = 0.0f;
    }

    if (l_collision_direction.y > 0.0f) // collision on the bottom
    {
        m_speed.y = 0.0f;
        m_can_jump = true;
    }
    else if (l_collision_direction.y < 0.0f)
    { // collision on the top
        m_speed.y = 0.0f;
    }
}

void Player::gameOver()
{
    m_speed.x = 0;
    m_speed.y = 0;
    m_health = 0;
    m_action = Action::DYING;
    m_bounding_box.move(2000, 2000);

    m_frame = 1;

    do
    {
        animation(4, 80, 48, 320);
    } while (m_frame != 0);
}

void Player::restartGame()
{
    if (m_score > m_score_record)
    {
        m_score_record = m_score;
    }
    m_score = 0;
    m_health = 5;
    m_bounding_box.setPosition(m_starting_position);
    m_lost = false;
}

void Player::animation(int l_frames, int l_ms, int l_starting_x, int l_starting_y)
{
    if (m_anim_clock.getElapsedTime() > sf::milliseconds(l_ms))
    {
        m_anim_clock.restart();
        if (m_frame < l_frames)
        {
            m_frame++;
        }
        if (m_frame == l_frames)
        {
            m_frame = 0;
        }
        m_player_sprite.setTextureRect(sf::IntRect(sf::Vector2i(l_starting_x * m_frame, l_starting_y), P_FRAMESIZE));
    }
}

void Player::update()
{
    m_speed.x = 0;

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
    {
        m_speed.x = -m_max_speed;
        setAction(Action::WALKING);
    }

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
    {
        m_speed.x = m_max_speed;
        setAction(Action::WALKING);
    }

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::W) && m_can_jump)
    {
        m_can_jump = false;
        m_speed.y = -m_jump_speed;
        // m_speed.y = -sqrt(2.0 * 100.0f * m_accel.y * m_jump_speed);
    }

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::X) && m_boost)
    {
        changeHealth(0);
        m_boost = false;
    }

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
    {
        m_speed.x /= 4;
        setAction(Action::ATTACKING);
    }

    m_speed.y += m_accel.y;

    if (m_speed.x == 0)
    {
        m_player_sprite.setTextureRect(sf::IntRect(sf::Vector2i(48, 128), P_FRAMESIZE));
    }

    if (m_action == Action::WALKING && m_speed.x < 0)
    {
        animation(4, 75, 48, 192);
    }
    if (m_action == Action::WALKING && m_speed.x > 0)
    {
        animation(4, 75, 48, 64);
    }
    if (m_action == Action::ATTACKING && m_speed.x < 0)
    {
        animation(4, 150, 48, 256);
    }
    if (m_action == Action::ATTACKING && m_speed.x > 0)
    {
        animation(4, 150, 48, 0);
    }

    m_bounding_box.move(m_speed);
    m_player_sprite.setPosition(m_bounding_box.getPosition().x, m_bounding_box.getPosition().y - 6);
}
void Player::render(sf::RenderWindow& l_window)
{
    // l_window.draw(m_bounding_box);
    l_window.draw(m_player_sprite);
}

} // namespace taic
