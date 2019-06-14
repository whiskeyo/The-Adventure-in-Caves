#include "Block.hpp"

Block::Block(sf::Vector2f l_position, sf::Color l_color)
{
    m_body.setSize(sf::Vector2f(W_BLOCKSIZE, W_BLOCKSIZE));
    m_body.setOrigin(sf::Vector2f(W_BLOCKSIZE / 2, W_BLOCKSIZE / 2));
    m_body.setFillColor(l_color);
    m_body.setPosition(l_position);
}

void Block::render(sf::RenderWindow& l_window)
{
    l_window.draw(m_body);
}
