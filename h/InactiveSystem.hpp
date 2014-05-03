#ifndef INACTIVESYSTEM_HPP_INCLUDED
#define INACTIVESYSTEM_HPP_INCLUDED

#include <SFML/Graphics.hpp>

class InactiveSystem
{
public:
    int init() {return 0;}
    void update(float fTime) {}
    void render(sf::RenderTarget& screen) {}
    void exit() {}
};

#endif // INACTIVESYSTEM_HPP_INCLUDED
