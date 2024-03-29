#ifndef WORLD_HPP
#define WORLD_HPP

#include <iostream>
#include <fstream>
#include <vector>
#include "Settings.hpp"
#include "Collider.hpp"
#include "Block.hpp"
#include "Coin.hpp"
#include "Heart.hpp"
#include "Portal.hpp"
#include "Enemy.hpp"
#include <SFML/Graphics.hpp>

class World
{
    public:
        World(std::string l_filename);
        ~World();

        void update();
        void render(sf::RenderWindow& l_window);

        std::vector<Block>   m_blocks;
        std::vector<Portal*> m_portals;
        std::vector<Coin*>   m_coins;
        std::vector<Heart*>  m_hearts;
        std::vector<Enemy*>  m_weak_enemies;
        std::vector<Enemy*>  m_strong_enemies;

        std::string  m_next_level;
        sf::Vector2f m_player_spawn_position;

    private:
        sf::Sprite  m_background_sprite;
};

#endif // WORLD_HPP
