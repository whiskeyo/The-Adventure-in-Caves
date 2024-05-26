#ifndef GAME_HPP
#define GAME_HPP

#include "HUD.hpp"
#include "Player.hpp"
#include "Window.hpp"
#include "World.hpp"

#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
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

    Window* getWindow();

private:
    Window m_window;
    sf::Clock m_clock;
    float m_elapsed;
    bool m_paused;
    bool m_restarted;

    unsigned int m_which_world;
    std::vector<World> m_world;
    Player m_player;
    HUD m_hud;
};

#endif
