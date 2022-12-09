#include "World.hpp"

World::World(std::string l_filename)
{
    // m_background_sprite.setTexture(ResourceManager::getInstance()->requestTexture("menu_background"),
    // true);
    std::ifstream level;
    level.open(l_filename.c_str());

    std::string background_name;
    float r, g, b; // it needs to read RGB values as floats to distinguish block
                   // types and colors
    int block_type;

    // level >> r >> g >> b;

    for (int block_y = 0; block_y < 18; block_y++)
    {
        for (int block_x = 0; block_x < 32; block_x++)
        {
            level >> block_type;
            switch (block_type)
            {
            case 1:
                m_blocks.push_back(Block(
                    sf::Vector2f(25 + block_x * W_BLOCKSIZE, 25 + block_y * W_BLOCKSIZE), sf::Color(100, 100, 100)));
                break;
            case 2:
                m_player_spawn_position = sf::Vector2f(29 + block_x * W_BLOCKSIZE, 25 + block_y * W_BLOCKSIZE);
                m_portals.push_back(
                    new Portal(sf::Vector2f(25 + block_x * W_BLOCKSIZE, 10 + block_y * W_BLOCKSIZE), 0));
                break;
            case 3:
                m_portals.push_back(
                    new Portal(sf::Vector2f(25 + block_x * W_BLOCKSIZE, 10 + block_y * W_BLOCKSIZE), 1));
                break;
            case 4:
                m_coins.push_back(new Coin(sf::Vector2f(25 + block_x * W_BLOCKSIZE, 25 + block_y * W_BLOCKSIZE)));
                break;
            case 5:
                m_hearts.push_back(new Heart(sf::Vector2f(25 + block_x * W_BLOCKSIZE, 25 + block_y * W_BLOCKSIZE)));
                break;
            case 6:
                m_weak_enemies.push_back(
                    new Enemy(6, sf::Vector2f(25 + block_x * W_BLOCKSIZE, 25 + block_y * W_BLOCKSIZE), 1, 2));
                break;
            case 7:
                m_weak_enemies.push_back(
                    new Enemy(7, sf::Vector2f(25 + block_x * W_BLOCKSIZE, 25 + block_y * W_BLOCKSIZE), 1, 2));
                break;
            case 8:
                m_strong_enemies.push_back(
                    new Enemy(8, sf::Vector2f(25 + block_x * W_BLOCKSIZE, 25 + block_y * W_BLOCKSIZE), 2, 4));
                break;
            case 9:
                m_strong_enemies.push_back(
                    new Enemy(9, sf::Vector2f(25 + block_x * W_BLOCKSIZE, 25 + block_y * W_BLOCKSIZE), 2, 4));
                break;

            default:
                break;
            }
        }
    }
    level >> background_name;
    level >> r >> g >> b;
    level.close();

    for (Block& block : m_blocks)
    {
        block.setColor((int)r, (int)g,
                       (int)b); // then we cast floats to ints to meet conditions
    }
    // of setColor function

    m_background_sprite.setTexture(ResourceManager::getInstance()->requestTexture(background_name), true);
}

World::~World()
{
    m_blocks.clear();
    m_portals.clear();
    m_coins.clear();
    m_hearts.clear();
    m_weak_enemies.clear();
    m_strong_enemies.clear();
}

void World::update()
{
    for (Portal* portal : m_portals)
    {
        portal->update();
    }

    for (Coin* coin : m_coins)
    {
        coin->update();
    }

    for (Heart* heart : m_hearts)
    {
        heart->update();
    }

    for (Enemy* enemy : m_weak_enemies)
    {
        enemy->update();
    }

    for (Enemy* enemy : m_strong_enemies)
    {
        enemy->update();
    }
}

void World::render(sf::RenderWindow& l_window)
{
    l_window.draw(m_background_sprite);

    for (Block& block : m_blocks)
    {
        block.render(l_window);
    }

    for (Portal* portal : m_portals)
    {
        portal->render(l_window);
    }

    for (Coin* coin : m_coins)
    {
        coin->render(l_window);
    }

    for (Heart* heart : m_hearts)
    {
        heart->render(l_window);
    }

    for (Enemy* enemy : m_weak_enemies)
    {
        enemy->render(l_window);
    }

    for (Enemy* enemy : m_strong_enemies)
    {
        enemy->render(l_window);
    }
}
