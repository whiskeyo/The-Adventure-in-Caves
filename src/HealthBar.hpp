#pragma once

#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Graphics/Sprite.hpp>
#include <SFML/System/Vector2.hpp>

class HealthBar
{
public:
    HealthBar(const sf::Vector2f& position);

    void render(sf::RenderWindow& window);

private:
    sf::Sprite heartSprite;
};
