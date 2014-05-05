#include "../h/CollisionManager.hpp"
#include "../h/ConstantManager.hpp"
#include <iostream>

void CollisionManager::Sector::checkCollisions(float fTime)
{
    for(std::list<CollisionObject*>::iterator i = m_localObjects.begin(); i != m_localObjects.end(); ++i)
    {
        std::list<CollisionObject*>::iterator j = i;
        j++;
        for(; j != m_localObjects.end(); j++)
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
            applyCircleCircle(a, b);

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

void CollisionManager::Sector::applyCircleCircle(CollisionObject* a, CollisionObject* b)
{
    Circle<float> boundA = a->getCircleBounds(), boundB = b->getCircleBounds();
    sf::Vector2f movA = a->getMovement(), movB = b->getMovement();

    sf::Vector2f difA = boundA.getPosition() - boundB.getPosition();
    sf::Vector2f difB = boundB.getPosition() - boundA.getPosition();
    if(difA.x * difA.x + difA.y * difA.y > (boundA.getRadius() + boundB.getRadius()) * (boundA.getRadius() + boundB.getRadius()))  // No Collision
        return;
    sf::Vector2f newdifA = difA + 0.00000001f * (a->getMovement()-b->getMovement());
    if(difA.x * difA.x + difA.y * difA.y < newdifA.x * newdifA.x + newdifA.y * newdifA.y) // Objects moving away from each other
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
}

int CollisionManager::init(sf::FloatRect bounds)
{
    int xResolution = std::stoi(getConstant("CollisionGridResolutionX"));
    int yResolution = std::stoi(getConstant("CollisionGridResolutionY"));
    m_bounds = bounds;
    m_resetDelay = static_cast<std::uint8_t>(std::stoi(getConstant("CollisionGridResetDelay")));
    sf::Vector2f sectorSize(m_bounds.width / static_cast<float>(xResolution), m_bounds.height / static_cast<float>(yResolution));
    m_sectors.clear();
    m_objects.clear();
    m_sectors.reserve(xResolution*yResolution);
    for(int x=0; x!=xResolution; x++)
    {
        for(int y=0; y!=yResolution; y++)
        {
            m_sectors.emplace_back(sf::FloatRect(sf::Vector2f(m_bounds.left + sectorSize.x * static_cast<float>(x),
                                                              m_bounds.top + sectorSize.y * static_cast<float>(y)),
                                                 sectorSize));
        }
    }

    m_updateStatus = 0;

    return 0;
}

void CollisionManager::exit()
{
    m_sectors.clear();
    m_objects.clear();
}

int CollisionManager::test()
{
try{return m_sectors.front().getObjects().size();}
catch(...){return -1;}
}

void CollisionManager::update(float fTime)
{
    if(m_updateStatus == 0)
    {
        refresh();
        m_updateStatus = m_resetDelay;
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

void CollisionManager::addObject(CollisionObject* object)
{
    m_objects.push_back(object);
    m_updateStatus = 0;
}

void CollisionManager::removeObject(CollisionObject* object)
{
    m_objects.remove(object);
    for(auto& i : m_sectors)
    {
        i.removeObject(object);
    }
    m_updateStatus = 0;
}

void CollisionManager::checkCollisions(float fTime)
{
    for(auto& i : m_sectors)
    {
        i.checkCollisions(fTime);
    }
}

void CollisionManager::refresh()
{
    for(auto& i : m_sectors)
    {
        i.reset();
        for(auto obj : m_objects)
        {
            if(i.getBounds().intersects(obj->getBoundingBox()))
            {
                i.addObject(obj);
            }
        }
    }
}
