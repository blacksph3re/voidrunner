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

template<typename T>
sf::Rect<T> expandToSquare(sf::Rect<T> input)
{
    T dif = input.width - input.height;
    if(div < 0) // Scale up width
    {
        input.width -= dif;
        input.left += dif / static_cast<T>(2);
    }
    else if(div > 0) // Scale up height
    {
        input.height += dif;
        input.top += dif / static_cast<T>(2);
    }
    return input;
}

#endif // DEFINITIONS_HPP_INCLUDED
