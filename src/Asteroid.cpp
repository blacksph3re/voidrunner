#include "../h/Asteroid.hpp"
#include "../h/ResourceManager.hpp"
#include "../h/ConstantManager.hpp"
#include <cstdlib>

int Asteroid::init(sf::Vector2f position)
{
    setPosition(position);
    setTexture(ResourceManager::get().getTexture("Asteroid"));
    float maxScale = std::stof(getConstant("AsteroidMaxScale"));
    float minScale = std::stof(getConstant("AsteroidMinScale"));
    float scale = minScale + static_cast<float>(rand())/(static_cast<float>(RAND_MAX/(maxScale-minScale)));
    setScale(scale, scale);
    setMass(scale * 1000);
    setOrigin(getLocalBounds().width * 0.5f, getLocalBounds().height * 0.5f);
    m_rotation = static_cast <float> (rand()) / (static_cast <float> (RAND_MAX/180.0f));
    return 0;
}

void Asteroid::update(float fTime)
{
    move(getMovement() * fTime);
    rotate(m_rotation * fTime);
}

void exit() {}
