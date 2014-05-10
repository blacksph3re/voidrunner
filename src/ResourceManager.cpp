#include "../h/ResourceManager.hpp"
#include "../h/ConstantManager.hpp"
#include <iostream>

ResourceManager& ResourceManager::get()
{
    static ResourceManager instance;
    return instance;
}

int ResourceManager::init()
{
    std::string imagefldr = getConstant("ImageFolder");

    m_failTexture.create(10, 10);

    if(!m_textures["Asteroid"].loadFromFile(imagefldr + "Asteroid.png"))
    {
        std::cerr << "[ResourceManager] Could not load Asteroid file" << std::endl;
        exit();
        return 1;
    }
    else {
        std::cerr << "[ResourceManager] Loaded Asteroid file" << std::endl;
    }
    m_textures["Asteroid"].setSmooth(true);

    if(!m_textures["Spaceship"].loadFromFile(imagefldr + "ship1.png"))
    {
        std::cerr << "[ResourceManager] Could not load Spaceship file" << std::endl;
        exit();
        return 1;
    } else {
        std::cerr << "[ResourceManager] Loaded Spaceship file" << std::endl;
    }
    m_textures["Spaceship"].setSmooth(true);


    if(!m_failFont.loadFromFile(imagefldr + "Default.ttf"))
    {
        std::cerr << "[ResourceManager] Could not load default font" << std::endl;
        exit();
        return 1;
    }

    return 0;
}

void ResourceManager::exit()
{
    m_textures.clear();
    m_fonts.clear();
}

const sf::Texture& ResourceManager::getTexture(std::string key)
{
    auto it = m_textures.find(key);
    if(it == m_textures.end())
    {
        std::cerr << "[Resource-Manager] Invalid texture-key: " << key << std::endl;
        return m_failTexture;
    }
    return it->second;
}

const sf::Font& ResourceManager::getFont(std::string key)
{
    if(key == "default" || key == "Default")
        return m_failFont;
    auto it = m_fonts.find(key);
    if(it == m_fonts.end())
    {
        std::cerr << "[Resource-Manager] Invalid font-key: " << key << std::endl;
        return m_failFont;
    }
    return it->second;
}
