#ifndef COLLIDER_HPP
#define COLLIDER_HPP

#include <SFML/Graphics.hpp>
#include <math.h>

class Collider
{
public:
    Collider(sf::RectangleShape& l_body);
    ~Collider();

    void move(float l_x, float l_y)
    {
        m_body.move(l_x, l_y);
    }
    sf::Vector2f getPosition()
    {
        return m_body.getPosition();
    }
    sf::Vector2f getHalfSize()
    {
        return m_body.getSize() / 2.0f;
    }

    // push means how hard is it to move the object (0 - easily, 1 - impossible)
    bool checkCollision(Collider l_other, sf::Vector2f& l_action, float l_push);

private:
    sf::RectangleShape& m_body;
};

#endif // COLLIDER_HPP
