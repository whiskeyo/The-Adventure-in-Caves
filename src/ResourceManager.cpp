#include "ResourceManager.hpp"

#include <assets/fonts/04B_30__.hpp>
#include <assets/textures/background1.hpp>
#include <assets/textures/background2.hpp>
#include <assets/textures/background3.hpp>
#include <assets/textures/background4.hpp>
#include <assets/textures/background5.hpp>
#include <assets/textures/background6.hpp>
#include <assets/textures/coin.hpp>
#include <assets/textures/enemy_strong_left.hpp>
#include <assets/textures/enemy_strong_right.hpp>
#include <assets/textures/enemy_weak_left.hpp>
#include <assets/textures/enemy_weak_right.hpp>
#include <assets/textures/heart.hpp>
#include <assets/textures/player.hpp>
#include <assets/textures/portal_bright.hpp>
#include <assets/textures/portal_dark.hpp>

ResourceManager::ResourceManager()
{
    loadTextureFromMemory(&TEXTURE_background1, sizeof(TEXTURE_background1), "background1");
    loadTextureFromMemory(&TEXTURE_background2, sizeof(TEXTURE_background2), "background2");
    loadTextureFromMemory(&TEXTURE_background3, sizeof(TEXTURE_background3), "background3");
    loadTextureFromMemory(&TEXTURE_background4, sizeof(TEXTURE_background4), "background4");
    loadTextureFromMemory(&TEXTURE_background5, sizeof(TEXTURE_background5), "background5");
    loadTextureFromMemory(&TEXTURE_background6, sizeof(TEXTURE_background6), "background6");
    loadTextureFromMemory(&TEXTURE_player, sizeof(TEXTURE_player), "player");
    loadTextureFromMemory(&TEXTURE_coin, sizeof(TEXTURE_coin), "coin");
    loadTextureFromMemory(&TEXTURE_heart, sizeof(TEXTURE_heart), "heart");
    loadTextureFromMemory(&TEXTURE_portal_bright, sizeof(TEXTURE_portal_bright), "portal_bright");
    loadTextureFromMemory(&TEXTURE_portal_dark, sizeof(TEXTURE_portal_dark), "portal_dark");
    loadTextureFromMemory(&TEXTURE_enemy_weak_left, sizeof(TEXTURE_enemy_weak_left), "enemy_weak_left");
    loadTextureFromMemory(&TEXTURE_enemy_weak_right, sizeof(TEXTURE_enemy_weak_right), "enemy_weak_right");
    loadTextureFromMemory(&TEXTURE_enemy_strong_left, sizeof(TEXTURE_enemy_strong_left), "enemy_strong_left");
    loadTextureFromMemory(&TEXTURE_enemy_strong_right, sizeof(TEXTURE_enemy_strong_right), "enemy_strong_right");
    loadFontFromMemory(&FONT_04B_30__, sizeof(FONT_04B_30__), "hud");
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
        this->m_textures[l_name] = texture;
}

void ResourceManager::loadTextureFromMemory(const void* data, std::size_t size, const std::string& textureName)
{
    sf::Texture texture;
    if (texture.loadFromMemory(data, size))
    {
        this->m_textures[textureName] = texture;
    }
}

void ResourceManager::loadFont(std::string l_path, std::string l_name)
{
    sf::Font font;
    if (font.loadFromFile(l_path))
        this->m_fonts[l_name] = font;
}

void ResourceManager::loadFontFromMemory(const void* data, std::size_t size, const std::string& fontName)
{
    sf::Font font;
    if (font.loadFromMemory(data, size))
    {
        this->m_fonts[fontName] = font;
    }
}
