#ifndef BLOCK_HPP
#define BLOCK_HPP

#include "Collider.hpp"
#include "Constants.hpp"

#include <SFML/Graphics.hpp>

class Block
{
public:
    Block(sf::Vector2f l_position, sf::Color l_color);
    void setColor(int l_r, int l_g, int l_b)
    {
        m_body.setFillColor(sf::Color(l_r, l_g, l_b));
    }

    void render(sf::RenderWindow& l_window);
    Collider getCollider()
    {
        return Collider(m_body);
    }

private:
    sf::RectangleShape m_body;
};

#endif // BLOCK_HPP
