#ifndef COLLECTIBLE_HPP
#define COLLECTIBLE_HPP

#include <SFML/Graphics.hpp>

class Collectible
{
    virtual void animation(int l_frames, int l_ms, int l_starting_x, int l_starting_y) = 0;
    virtual void update() = 0;
    virtual void render(sf::RenderWindow& l_window) = 0;
};

#endif // COLLECTIBLE_HPP
