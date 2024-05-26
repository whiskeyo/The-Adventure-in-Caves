#include "HealthBar.hpp"

#include "ResourceManager.hpp"
#include "Settings.hpp"

HealthBar::HealthBar(const sf::Vector2f& position)
{
    heartSprite.setTexture(ResourceManager::getInstance()->requestTexture("heart"), true);
    heartSprite.setTextureRect(sf::IntRect(sf::Vector2i(0, 0), H_FRAMESIZE));
    heartSprite.scale(0.2f, 0.2f);
    heartSprite.setPosition(position);
}

void HealthBar::render(sf::RenderWindow& window)
{
    window.draw(heartSprite);
}
