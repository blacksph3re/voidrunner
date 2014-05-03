#ifndef COLLISIONOBJECT_HPP_INCLUDED
#define COLLISIONOBJECT_HPP_INCLUDED

#include <SFML/Graphics.hpp>
#include "Definitions.hpp"

class CollisionObject : public sf::Sprite
{
protected:
    sf::Vector2f    m_movement;
    sf::FloatRect   m_boundingBox;
    float           m_mass;         // Mass must not be 0
public:

    const sf::Vector2f& getMovement() const {return m_movement;}
    void                setMovement(sf::Vector2f val) {m_movement = val;}
    float               getMass() const {return m_mass;}

    /**
     * Returns the shape type that best approximizes the shape of the object
     * The corresponding getXBounds function should be overloaded
    */
    enum Shapes
    {
        CIRCLE,
        SIMPLE_RECT,
        COMPLEX_RECT
    };
    virtual Shapes getShape() = 0;

    /**
     * Gets the bounds of the object that shall be used for collision detection
     * In global coordinates
     * Must not exceed limits of getBoundingBox
     * Standart-implementations are given, but it is recommendet to rewrite them to your need
    */
    virtual sf::RectangleShape  getComplexRectBounds() const;
    virtual sf::FloatRect       getSimpleRectBounds() const;
    virtual Circle<float>       getCircleBounds() const;

    inline const sf::FloatRect& getBoundingBox() const {return m_boundingBox;}

    virtual ~CollisionObject() {}
};

#endif // COLLISIONOBJECT_HPP_INCLUDED
