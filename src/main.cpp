/*
    Course: Objective Oriented Programming (summer semester, 2019)
    Name: Tomasz Woszczynski
    Student no: 307690
    Project type: platformer game – „The Adventure in Caves”
    Additional libraries: SFML 2.5.1
    Operating system: Ubuntu 18.10

 */

#include "Game.hpp"
#include "ResourceManager.hpp"
#include "Window.hpp"

#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <string>

int main()
{
    Game game;
    game.run();

    return EXIT_SUCCESS;
}
