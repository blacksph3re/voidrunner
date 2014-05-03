#ifndef ASTEROID_HPP_INCLUDED
#define ASTEROID_HPP_INCLUDED

#include "CollisionObject.hpp"

class Asteroid : public CollisionObject
{
private:
    float m_rotation;
public:
    CollisionObject::Shapes getShape() {return CIRCLE;}
    sf::FloatRect getBoundingBox() const {return getGlobalBounds();}

    int init(sf::Vector2f position);
    void update(float fTime);
    void exit();

    Asteroid() {}
    ~Asteroid() {}
};

#endif // ASTEROID_HPP_INCLUDED
