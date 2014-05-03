/**
 * The space is divided into several solar systems, of which only one is active (the one with the player in it)
 * The others are stored as abstract data
*/

#ifndef SPACE_HPP_INCLUDED
#define SPACE_HPP_INCLUDED

#include <SFML/Graphics.hpp>
#include <vector>
#include "ActiveSystem.hpp"
#include "InactiveSystem.hpp"


class Space
{
private:
    ActiveSystem                                m_activeSystem;
    sf::Vector2<std::size_t>                    m_activeIndex;

    std::vector<std::vector<InactiveSystem>>    m_inactiveSystems;
    float                                       m_inactiveUpdateTimer;
    float                                       m_inactiveUpdateDelay;

public:

    int init();
    void update(float fTime);
    void render(sf::RenderTarget& screen);
    void exit();

    Space() {}
    ~Space() {}
};

#endif // SPACE_HPP_INCLUDED
