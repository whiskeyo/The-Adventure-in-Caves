#ifndef GAME_HPP
#define GAME_HPP

#include "Coin.hpp"
#include "Enemy.hpp"
#include "HUD.hpp"
#include "Heart.hpp"
#include "Player.hpp"
#include "ResourceManager.hpp"
#include "Window.hpp"
#include "World.hpp"

#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <chrono>
#include <iostream>
#include <string>
#include <thread>
#include <vector>

class Game
{
public:
    Game();
    ~Game();

    void run(); // main game loop

    void loadLevels();
    void update();
    void render();

    Window* getWindow()
    {
        return &m_window;
    }

private:
    Window m_window;
    sf::Clock m_clock;
    float m_elapsed;
    bool m_paused;
    bool m_restarted;

    unsigned int m_which_world;
    std::vector<World> m_world;
    taic::Player m_player;
    HUD m_hud;
};

#endif
