#ifndef RESOURCEMANAGER_HPP_INCLUDED
#define RESOURCEMANAGER_HPP_INCLUDED

#include <SFML/Graphics.hpp>
#include <map>
#include <string>

class ResourceManager : public sf::NonCopyable
{
private:
    std::map<std::string, sf::Texture>  m_textures;
    sf::Texture                         m_failTexture;

    ResourceManager() {}
public:
    static ResourceManager& get();

    const sf::Texture& getTexture(std::string key);

    int init();
    void exit();
};


#endif // RESOURCEMANAGER_HPP_INCLUDED
