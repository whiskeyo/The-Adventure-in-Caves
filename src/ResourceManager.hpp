#ifndef RESOURCEMANAGER_HPP
#define RESOURCEMANAGER_HPP

#include <SFML/Graphics.hpp>
#include <map>
#include <string>

class ResourceManager
{
public:
    ~ResourceManager();
    static ResourceManager* getInstance()
    {
        static ResourceManager instance;
        return &instance;
    }

    void cleanUp();

    sf::Texture& requestTexture(std::string l_name)
    {
        return this->m_textures[l_name];
    }
    sf::Font& requestFont(std::string l_name)
    {
        return this->m_fonts[l_name];
    }

private:
    ResourceManager();
    void loadTexture(std::string l_path, std::string l_name);
    void loadTextureFromMemory(const void* data, std::size_t size, const std::string& textureName);
    void loadFont(std::string l_path, std::string l_name);
    void loadFontFromMemory(const void* data, std::size_t size, const std::string& fontName);

    std::map<std::string, sf::Texture> m_textures;
    std::map<std::string, sf::Font> m_fonts;
};

#endif // RESOURCEMANAGER_HPP
