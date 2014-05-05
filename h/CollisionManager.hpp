/**
 * A control structure that holds collision entities and monitors efficiently for collisions
*/

#ifndef COLLISIONMANAGER_HPP_INCLUDED
#define COLLISIONMANAGER_HPP_INCLUDED

#include <SFML/System/NonCopyable.hpp>
#include <list>
#include <vector>
#include "CollisionObject.hpp"

class CollisionManager
{
private:
    class Sector
    {
    private:
        std::list<CollisionObject*> m_localObjects;
        sf::FloatRect               m_bounds;

        void applyCollision(CollisionObject* a, CollisionObject* b, float fTime);

        void applyCircleCircle(CollisionObject* a, CollisionObject* b);
        void applyRectCircle(CollisionObject* a, CollisionObject* b, float fTime);  // Not implemented yet
        void applyRectRect(CollisionObject* a, CollisionObject* b, float fTime);  // Not implemented yet

    public:
        const sf::FloatRect& getBounds() const {return m_bounds;}
        const std::list<CollisionObject*>& getObjects() const {return m_localObjects;}

        void reset() {m_localObjects.clear();}
        void addObject(CollisionObject* object) {m_localObjects.push_back(object);}
        void removeObject(CollisionObject* object) {m_localObjects.remove(object);}

        void checkCollisions(float fTime);

        Sector(sf::FloatRect bounds) : m_bounds(bounds) {}
        ~Sector() {}
    };

    std::uint8_t                        m_resetDelay ; // Wait n Frames until next full grid reset

    std::vector<Sector>                 m_sectors;
    std::list<CollisionObject*>         m_objects;
    sf::FloatRect                       m_bounds;
    std::uint8_t                        m_updateStatus; // 0 - Update, everything else - frames to next update

public:

    void removeObject(CollisionObject* object);
    void addObject(CollisionObject* object);
    int test();

    void refresh();
    void checkCollisions(float fTime);

    int init(sf::FloatRect bounds);
    void update(float fTime);
    void renderGrid(sf::RenderTarget &screen);
    void exit();

    CollisionManager() {}
    ~CollisionManager() {}
};

#endif // COLLISIONMANAGER_HPP_INCLUDED
