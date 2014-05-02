/**
 * A control structure that holds collision entities and monitors efficiently for collisions
*/

#ifndef COLLISIONMANAGER_HPP_INCLUDED
#define COLLISIONMANAGER_HPP_INCLUDED

#include <list>
#include <vector>
#include "CollisionObject.hpp"

class CollisionManager
{
private:
    class Sector
    {
    private:
        std::list<CollisionObject*> m_objects;
        sf::FloatRect               m_bounds;
    public:
        const sf::FloatRect& getBounds() const {return m_bounds;}

        void reset() {m_objects.clear();}
        void addObject(CollisionObject* object) {m_objects.push_back(object);}

        void checkCollisions();

        Sector(sf::FloatRect bounds) : m_bounds(bounds) {}
        ~Sector() {}
    };

    static const int xResolution = 3;
    static const int yResolution = 3;

    std::vector<std::vector<Sector>>    m_sectors;
    std::list<CollisionObject*>         m_objects;
    sf::FloatRect                       m_outerBounds;
    std::uint8_t                        m_updateStatus; // 0 - Update, everything else - frames to next update

public:



};

#endif // COLLISIONMANAGER_HPP_INCLUDED
