#include "../h/../h/CollisionObject.hpp"
#include <cmath>

sf::RectangleShape CollisionObject::getComplexRectBounds() const
{
    sf::FloatRect tmp = getBoundingBox();
    sf::RectangleShape retval;
    retval.setSize(sf::Vector2f(tmp.width, tmp.height));
    retval.setPosition(sf::Vector2f(tmp.top, tmp.left));
    return retval;
}

sf::FloatRect CollisionObject::getSimpleRectBounds() const
{
    return getBoundingBox();
}

Circle<float> CollisionObject::getCircleBounds() const
{
    sf::FloatRect tmp = getBoundingBox();
    Circle<float> retval;
    retval.setPosition(sf::Vector2f(tmp.left, tmp.top) + (sf::Vector2f(tmp.width, tmp.height)*0.5f));
    retval.setRadius((tmp.width < tmp.height ? tmp.width : tmp.height) * 0.5f);
    return retval;
}
