#include "ResourceManager.hpp"

ResourceManager::ResourceManager()
{
    loadTexture("textures/background1.jpg", "background1");
    loadTexture("textures/background2.jpg", "background2");
    loadTexture("textures/background3.png", "background3");
    loadTexture("textures/background4.png", "background4");
    loadTexture("textures/background5.jpg", "background5");
    loadTexture("textures/background6.jpg", "background6");
    loadTexture("textures/player.png", "player");
    loadTexture("textures/coin.png", "coin");
    loadTexture("textures/heart.png", "heart");
    loadTexture("textures/portal_bright.png", "portal_bright");
    loadTexture("textures/portal_dark.png", "portal_dark");
    loadTexture("textures/enemy_weak_left.png", "enemy_weak_left");
    loadTexture("textures/enemy_weak_right.png", "enemy_weak_right");
    loadTexture("textures/enemy_strong_left.png", "enemy_strong_left");
    loadTexture("textures/enemy_strong_right.png", "enemy_strong_right");

    loadFont("fonts/04B_30__.TTF", "hud");
}

ResourceManager::~ResourceManager()
{
}

void ResourceManager::cleanUp()
{
    m_textures.clear();
    m_fonts.clear();
}

void ResourceManager::loadTexture(std::string l_path, std::string l_name)
{
    sf::Texture texture;
    if (texture.loadFromFile(l_path))
    {
        this->m_textures[l_name] = texture;
    }
}

void ResourceManager::loadFont(std::string l_path, std::string l_name)
{
    sf::Font font;
    if (font.loadFromFile(l_path))
    {
        this->m_fonts[l_name] = font;
    }
}
