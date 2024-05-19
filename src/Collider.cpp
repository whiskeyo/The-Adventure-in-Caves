#include "Collider.hpp"

Collider::Collider(sf::RectangleShape& l_body) : m_body(l_body)
{
}

Collider::~Collider()
{
}

bool Collider::checkCollision(Collider l_other, sf::Vector2f& l_direction, float l_push)
{
    sf::Vector2f other_position = l_other.getPosition();
    sf::Vector2f other_halfsize = l_other.getHalfSize();
    sf::Vector2f this_position = getPosition();
    sf::Vector2f this_halfsize = getHalfSize();

    float delta_x = other_position.x - this_position.x;
    float delta_y = other_position.y - this_position.y;
    float intersect_x = fabs(delta_x) - (other_halfsize.x + this_halfsize.x);
    float intersect_y = fabs(delta_y) - (other_halfsize.y + this_halfsize.y);

    if (intersect_x < 0.0f && intersect_y < 0.0f)
    {
        l_push = std::min(std::max(l_push, 0.0f), 1.0f);

        if (intersect_x > intersect_y)
        {
            if (delta_x > 0.0f)
            {
                move(intersect_x * (1.0f - l_push), 0.0f);
                l_other.move(-intersect_x * l_push, 0.0f);
                l_direction.x = 1.0f;
                l_direction.y = 0.0f;
            }
            else
            {
                move(-intersect_x * (1.0f - l_push), 0.0f);
                l_other.move(intersect_x * l_push, 0.0f);
                l_direction.x = -1.0f;
                l_direction.y = 0.0f;
            }
        }
        else
        {
            if (delta_y > 0.0f)
            {
                move(0.0f, intersect_y * (1.0f - l_push));
                l_other.move(0.0f, -intersect_y * l_push);
                l_direction.x = 0.0f;
                l_direction.y = -1.0f;
            }
            else
            {
                move(0.0f, -intersect_y * (1.0f - l_push));
                l_other.move(0.0f, intersect_y * l_push);
                l_direction.x = 0.0f;
                l_direction.y = 1.0f;
            }
        }
        return true;
    }
    return false;
}
