#ifndef ASTEROID_HPP_INCLUDED
#define ASTEROID_HPP_INCLUDED

#include "CollisionObject.hpp"

class Asteroid : public CollisionObject
{
private:

public:
    CollisionObject::Shapes getShape() {return CIRCLE;}

    Asteroid();
    ~Asteroid();
};

#endif // ASTEROID_HPP_INCLUDED
