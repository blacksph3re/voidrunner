#ifndef DEFINITIONS_HPP_INCLUDED
#define DEFINITIONS_HPP_INCLUDED

#include <SFML/System.hpp>

template<typename T>
class Circle
{
private:
    sf::Vector2<T> m_pos;
    T m_radius;

public:
    T getRadius() {return m_radius;}
    sf::Vector2<T> getPosition() {return m_pos;}
    void setRadius(T val) {m_radius = val;}
    void setPosition(sf::Vector2<T> val) {m_pos = val;}

    Circle() : m_pos(sf::Vector2<T>(0, 0)), m_radius(0) {}
    Circle(sf::Vector2<T> p_pos, T p_radius) : m_pos(p_pos), m_radius(p_radius) {}
    Circle(const Circle &rhs) : m_pos(rhs.m_pos), m_radius(rhs.m_radius) {}
    const Circle& operator = (const Circle &rhs) {m_pos = rhs.m_pos; m_radius=rhs.m_radius; return *this;}
};

#endif // DEFINITIONS_HPP_INCLUDED
