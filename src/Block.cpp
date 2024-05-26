#include "Block.hpp"

Block::Block(sf::Vector2f position, sf::Color color)
{
    m_body.setSize(sf::Vector2f(W_BLOCKSIZE, W_BLOCKSIZE));
    m_body.setOrigin(sf::Vector2f(W_BLOCKSIZE / 2, W_BLOCKSIZE / 2));
    m_body.setFillColor(color);
    m_body.setPosition(position);
}

void Block::setColor(const std::uint8_t red, const std::uint8_t green, const std::uint8_t blue)
{
    m_body.setFillColor(sf::Color(red, green, blue));
}

void Block::render(sf::RenderWindow& window)
{
    window.draw(m_body);
}

Collider Block::getCollider()
{
    return Collider(m_body);
}
