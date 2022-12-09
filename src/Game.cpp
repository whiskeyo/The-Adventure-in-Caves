#include "Game.hpp"

Game::Game()
    : m_window("The Adventure in Caves", sf::Vector2u(W_WIDTH, W_HEIGHT)), m_player("levels/level1.txt"),
      m_hud(&m_player)
{
    loadLevels();
    m_restarted = false;
    m_which_world = 0;
    m_clock.restart();
    m_elapsed = 0.0f;
}

Game::~Game()
{
    ResourceManager::getInstance()->cleanUp();
}

void Game::run()
{
    while (not m_window.isDone())
    {
        if (m_clock.getElapsedTime().asSeconds() >= 1.0f / W_FRAMERATE)
        {
            m_window.update(); // it is here to allow as to pause the game

            if (m_window.isFocused() and not m_window.isPaused())
            {
                update();
            }

            render();
            m_clock.restart();
        }
    }
}

void Game::loadLevels()
{
    // m_world.push_back(World("levels/level0init.txt"));
    m_world.push_back(World("levels/level1.txt"));
    m_world.push_back(World("levels/level2.txt"));
    m_world.push_back(World("levels/level3.txt"));
    m_world.push_back(World("levels/level4.txt"));
    m_world.push_back(World("levels/level5.txt"));
    m_world.push_back(World("levels/goodjob.txt"));
}

void Game::update()
{
    m_restarted = false;
    // Check collisions of player and blocks
    for (Block& block : m_world[m_which_world].m_blocks)
    {
        if (block.getCollider().checkCollision(m_player.getCollider(), m_player.m_collision_direction, 1.0f))
        {
            m_player.onCollision(m_player.m_collision_direction);
        }
    }

    // Check if player and enemy are in range to fight with each other
    for (Enemy* enemy : m_world[m_which_world].m_weak_enemies)
    {
        if (enemy->getCollider().checkCollision(m_player.getCollider(), m_player.m_collision_direction, 0.0f))
        {
            if (m_player.getAction() == Action::ATTACKING && m_player.canAttack())
            {
                (m_player.attack(enemy));
            }

            // If player is in range of enemy for more than 1.2 sec, then enemy can
            // attack.
            if (enemy->m_attack_clock.getElapsedTime() > sf::seconds(0.8f))
            {
                enemy->m_attack_clock.restart();
            }
            enemy->setAction(Action::ATTACKING);
            if (enemy->canAttack())
            {
                enemy->attack(&m_player);
            }
        }
        else
        {
            enemy->setAction(Action::NONE);
        }
    }

    for (Enemy* enemy : m_world[m_which_world].m_strong_enemies)
    {
        if (enemy->getCollider().checkCollision(m_player.getCollider(), m_player.m_collision_direction, 0.0f))
        {
            if (m_player.getAction() == Action::ATTACKING && m_player.canAttack())
            {
                (m_player.attack(enemy));
            }

            if (enemy->m_attack_clock.getElapsedTime() > sf::seconds(1.0f))
            {
                enemy->m_attack_clock.restart();
            }
            enemy->setAction(Action::ATTACKING);
            if (enemy->canAttack())
            {
                enemy->attack(&m_player);
            }
        }
        else
        {
            enemy->setAction(Action::NONE);
        }
    }

    // If enemy has 0 (or less) health points, erase it from vector and add points
    // for player
    for (auto it = m_world[m_which_world].m_weak_enemies.begin(); it != m_world[m_which_world].m_weak_enemies.end();)
    {
        if ((*it)->getHealth() <= 0)
        {
            it = m_world[m_which_world].m_weak_enemies.erase(it);
            m_player.changeScore(5);
        }
        else
        {
            ++it;
        }
    }

    for (auto it = m_world[m_which_world].m_strong_enemies.begin();
         it != m_world[m_which_world].m_strong_enemies.end();)
    {
        if ((*it)->getHealth() <= 0)
        {
            it = m_world[m_which_world].m_strong_enemies.erase(it);
            m_player.changeScore(15);
        }
        else
        {
            ++it;
        }
    }

    // Checking if player gets collectibles
    for (auto it = m_world[m_which_world].m_coins.begin(); it != m_world[m_which_world].m_coins.end();)
    {
        if ((*it)->getCollider().checkCollision(m_player.getCollider(), m_player.m_collision_direction, 0.0f))
        {
            it = m_world[m_which_world].m_coins.erase(it);
            m_player.changeScore(1);
        }
        else
        {
            ++it;
        }
    }

    for (auto it = m_world[m_which_world].m_hearts.begin(); it != m_world[m_which_world].m_hearts.end();)
    {
        if ((*it)->getCollider().checkCollision(m_player.getCollider(), m_player.m_collision_direction, 0.0f))
        {
            it = m_world[m_which_world].m_hearts.erase(it);
            m_player.changeHealth(1);
        }
        else
        {
            ++it;
        }
    }

    // Check if player stands on the portal to the next level
    for (Portal* portal : m_world[m_which_world].m_portals)
    {
        if (portal->getCollider().checkCollision(m_player.getCollider(), m_player.m_collision_direction, 0.0f))
        {
            if (portal->whichType() == 1 && portal->m_portal_clock.getElapsedTime() > sf::seconds(1.0f))
            {
                portal->m_portal_clock.restart();
            }
            if (portal->whichType() == 1 && portal->canTeleport())
            {
                m_which_world++;
                m_player.setPosition(m_world[m_which_world].m_player_spawn_position);
            }
        }
    }

    if (m_which_world + 1 > m_world.size())
    {
        m_which_world = 0;
        m_player.setPosition(m_world[m_which_world].m_player_spawn_position);
    }

    if (m_player.getHealth() > 0)
    {
        m_hud.update();
        m_player.update();
    }
    else if (!m_player.hasLost())
    {
        m_hud.m_health.clear();

        m_player.gameOver();

        m_player.lose();
    }

    // m_player.gameOver();
    // m_player.stopDeathAnimation();

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::R) && !m_restarted)
    {
        // m_player.restartGame();
        m_world.clear();
        loadLevels(); // reload world levels
        std::this_thread::sleep_for(std::chrono::milliseconds(300));
        m_player.restartGame();
        m_restarted = true;
        m_which_world = 0;
    }

    m_world[m_which_world].update();
    // m_hud.update();
    // m_player.update();
}

void Game::render()
{
    m_window.beginDraw();

    m_world[m_which_world].render(*m_window.getRenderWindow());
    m_hud.render(*m_window.getRenderWindow());
    m_player.render(*m_window.getRenderWindow());

    m_window.endDraw();
}
