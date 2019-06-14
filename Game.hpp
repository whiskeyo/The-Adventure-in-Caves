#ifndef GAME_HPP
#define GAME_HPP

#include <SFML/Window.hpp>
#include <SFML/System.hpp>
#include <SFML/Graphics.hpp>
#include "ResourceManager.hpp"
#include "Window.hpp"
#include "HUD.hpp"
#include "World.hpp"
#include "Player.hpp"
#include "Enemy.hpp"
#include "Coin.hpp"
#include "Heart.hpp"
#include <thread>
#include <chrono>
#include <vector>
#include <iostream>
#include <string>

class Game
{
    public:
        Game();
        ~Game();

        void run();     // main game loop

        void loadLevels();
        void update();
        void render();

        Window* getWindow() { return &m_window; }

    private:
        Window m_window;
        sf::Clock m_clock;
        float m_elapsed;
        bool m_paused;
        bool m_restarted;

        unsigned int m_which_world;
        std::vector<World> m_world;
        Player m_player;
        HUD    m_hud;
};

#endif
