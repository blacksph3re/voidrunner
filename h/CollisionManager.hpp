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

        void applyCollision(CollisionObject* a, CollisionObject* b, float fTime);

        void applyCircleCircle(CollisionObject* a, CollisionObject* b, float fTime);
        void applyRectCircle(CollisionObject* a, CollisionObject* b, float fTime);
        void applyRectRect(CollisionObject* a, CollisionObject* b, float fTime);

    public:
        const sf::FloatRect& getBounds() const {return m_bounds;}

        void reset() {m_objects.clear();}
        void addObject(CollisionObject* object) {m_objects.push_back(object);}
        void removeObject(CollisionObject* object) {m_objects.remove(object);}

        void checkCollisions(float fTime);

        Sector(sf::FloatRect bounds) : m_bounds(bounds) {}
        ~Sector() {}
    };

    static const int xResolution = 3;
    static const int yResolution = 3;
    static const std::uint8_t resetDelay = 2; // Wait 2 Frames until next full grid reset

    std::vector<std::vector<Sector>>    m_sectors;
    std::list<CollisionObject*>         m_objects;
    sf::FloatRect                       m_bounds;
    std::uint8_t                        m_updateStatus; // 0 - Update, everything else - frames to next update

public:

    void removeObject(CollisionObject* object);

    void refresh();
    void checkCollisions(float fTime);

    void update(float fTime);
    void renderBounds(sf::RenderTarget &screen);
    void renderGrid(sf::RenderTarget &screen);

    CollisionManager(sf::FloatRect bounds);
    ~CollisionManager() {}
};

#endif // COLLISIONMANAGER_HPP_INCLUDED
