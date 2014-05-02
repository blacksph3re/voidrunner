#include "../h/CollisionManager.hpp"

void CollisionManager::Sector::checkCollisions(float fTime)
{
    for(std::list<CollisionObject*>::iterator i = m_objects.begin(); i != m_objects.end(); ++i)
    {
        std::list<CollisionObject*>::iterator j = i;
        j++;
        for(; j != m_objects.end(); j++)
        {
            if((*i)->getBoundingBox().intersects((*j)->getBoundingBox()))
            {
                applyCollision(*i, *j, fTime);
            }
        }
    }
}

void CollisionManager::Sector::applyCollision(CollisionObject* a, CollisionObject* b, float fTime)
{
    if(a->getShape() == CollisionObject::Shapes::CIRCLE)
    {
        if(b->getShape() == CollisionObject::Shapes::CIRCLE)
            applyCircleCircle(a, b, fTime);

        else if(b->getShape() == CollisionObject::Shapes::COMPLEX_RECT)
        {}

        else if(b->getShape() == CollisionObject::Shapes::SIMPLE_RECT)
            applyRectCircle(a, b, fTime);

        else
            applyCollision(b, a, fTime);
    }
    else if(a->getShape() == CollisionObject::Shapes::COMPLEX_RECT)
    {}
    else if(a->getShape() == CollisionObject::Shapes::SIMPLE_RECT)
    {
        if(b->getShape() == CollisionObject::Shapes::SIMPLE_RECT)
            applyRectRect(a, b, fTime);
        else
            applyCollision(b, a, fTime);
    }
}

void CollisionManager::Sector::applyRectRect(CollisionObject* a, CollisionObject* b, float fTime)
{
}

void CollisionManager::Sector::applyRectCircle(CollisionObject* a, CollisionObject* b, float fTime)
{
}

void CollisionManager::Sector::applyCircleCircle(CollisionObject* a, CollisionObject* b, float fTime)
{

    Circle<float> boundA = a->getCircleBounds(), boundB = b->getCircleBounds();
    sf::Vector2f movA = a->getMovement(), movB = b->getMovement();

    sf::Vector2f difA = boundA.getPosition() - boundB.getPosition();
    sf::Vector2f difB = boundB.getPosition() - boundA.getPosition();
    if(difA.x * difA.x + difA.y * difA.y > boundA.getRadius() + boundB.getRadius())  // No Collision
        return;

    float dotA = (movA.x - movB.x) * (boundA.getPosition().x - boundB.getPosition().x) +
                 (movA.y - movB.y) * (boundA.getPosition().y - boundB.getPosition().y);

    float dotB = (movB.x - movA.x) * (boundB.getPosition().x - boundA.getPosition().x) +
                 (movB.y - movA.y) * (boundB.getPosition().y - boundA.getPosition().y);

    dotA *= (2 * b->getMass()) / (a->getMass() + b->getMass());
    dotB *= (2 * a->getMass()) / (a->getMass() + b->getMass());

    dotA /= (difA.x * difA.x + difA.y * difA.y);
    dotB /= (difB.x * difB.x + difB.y * difB.y);

    movA -= dotA * difA;
    movB -= dotB * difB;

    a->setMovement(movA);
    b->setMovement(movB);

    // Move both a frame, so objects dont stick inside another
    a->move(movA * fTime);
    b->move(movB * fTime);
}

CollisionManager::CollisionManager(sf::FloatRect bounds)
: m_bounds(bounds), m_updateStatus(0)
{
    sf::Vector2f sectorSize(m_bounds.width / static_cast<float>(xResolution),
                            m_bounds.height / static_cast<float>(yResolution));
    m_sectors.clear();
    m_sectors.reserve(xResolution);
    for(int x=0; x!=xResolution; x++)
    {
        m_sectors.emplace_back();
        for(int y=0; y!=yResolution; y++)
        {
            m_sectors[x].emplace_back(sf::FloatRect(sf::Vector2f(sectorSize.x * static_cast<float>(x), sectorSize.y * static_cast<float>(y)),
                                                    sf::Vector2f(sectorSize.x * static_cast<float>(x+1), sectorSize.y * static_cast<float>(y+1))));
        }
    }
}


void CollisionManager::update(float fTime)
{
    if(m_updateStatus == 0)
    {
        refresh();
        m_updateStatus = resetDelay;
    }
    else
        m_updateStatus--;

    checkCollisions(fTime);
}

void CollisionManager::renderBounds(sf::RenderTarget &screen)
{
}

void CollisionManager::renderGrid(sf::RenderTarget &screen)
{
}

void CollisionManager::removeObject(CollisionObject* object)
{
    m_objects.remove(object);
    for(auto x : m_sectors)
    {
        for(auto y : x)
        {
            y.removeObject(object);
        }
    }
}

void CollisionManager::checkCollisions(float fTime)
{
    for(auto x : m_sectors)
    {
        for(auto y : x)
        {
            y.checkCollisions(fTime);
        }
    }
}

void CollisionManager::refresh()
{
    for(auto x : m_sectors)
    {
        for(auto y : x)
        {
            y.reset();
            for(auto obj : m_objects)
            {
                if(y.getBounds().intersects(obj->getBoundingBox()))
                    y.addObject(obj);
            }
        }
    }
}
