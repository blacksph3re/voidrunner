#ifndef ACTIVESYSTEM_HPP_INCLUDED
#define ACTIVESYSTEM_HPP_INCLUDED

#include "InactiveSystem.hpp"
#include "CollisionManager.hpp"

class ActiveSystem
{
private:
    CollisionManager    m_colMgr;
    sf::FloatRect       m_borders;
public:

    int init(const InactiveSystem& systemData);
    void update(float fTime);
    void render(sf::RenderTarget& screen);
    void exit();
};

#endif // ACTIVESYSTEM_HPP_INCLUDED
