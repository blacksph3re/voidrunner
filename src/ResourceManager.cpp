#include "../h/../h/ResourceManager.hpp"
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
    m_textures["Asteroid"].setSmooth(true);

    return 0;
}

void ResourceManager::exit()
{
    m_textures.clear();
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
