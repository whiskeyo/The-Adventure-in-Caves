#ifndef BLOCK_HPP
#define BLOCK_HPP

#include "Collider.hpp"
#include "Settings.hpp"

#include <SFML/Graphics.hpp>

class Block
{
public:
    Block(sf::Vector2f position, sf::Color color);

    void setColor(const std::uint8_t red, const std::uint8_t green, const std::uint8_t blue);
    void render(sf::RenderWindow& window);
    Collider getCollider();

private:
    sf::RectangleShape m_body;
};

#endif // BLOCK_HPP
