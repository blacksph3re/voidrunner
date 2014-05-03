#ifndef ACTIVESYSTEM_HPP_INCLUDED
#define ACTIVESYSTEM_HPP_INCLUDED

#include "InactiveSystem.hpp"
#include "CollisionManager.hpp"
#include "Asteroid.hpp"
#include <list>

class ActiveSystem
{
private:
    CollisionManager    m_collisionMgr;
    sf::FloatRect       m_borders;
    std::list<Asteroid> m_asteroids;
    unsigned int        m_minAsteroidCount;


public:

    int init(const InactiveSystem& systemData);
    void update(float fTime);
    void render(sf::RenderTarget& screen);
    void exit();
};

#endif // ACTIVESYSTEM_HPP_INCLUDED
