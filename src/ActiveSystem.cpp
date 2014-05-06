#include "../h/ActiveSystem.hpp"
#include "../h/ConstantManager.hpp"

int ActiveSystem::init(const InactiveSystem& data)
{
    m_borders.width = std::stof(getConstant("SystemSizeX"));
    m_borders.height = std::stof(getConstant("SystemSizeY"));
    m_borders.left = m_borders.width * -0.5f;
    m_borders.top = m_borders.height * -0.5f;

    if(m_collisionMgr.init(m_borders) != 0)
        return 1;

    m_minAsteroidCount = static_cast<unsigned int>(std::stoi(getConstant("AsteroidCount")));
    float maxAsteroidSpeed = std::stof(getConstant("AsteroidMaxSpeed"));
    m_asteroids.clear();
    for(unsigned int i = 0; i < m_minAsteroidCount; i++)
    {
        m_asteroids.emplace_back();
        m_asteroids.back().init(sf::Vector2f(m_borders.left + static_cast <float> (rand()) /( static_cast <float> (RAND_MAX/(m_borders.width))),
                                             m_borders.top + static_cast <float> (rand()) /( static_cast <float> (RAND_MAX/(m_borders.height)))));
        m_asteroids.back().setMovement(sf::Vector2f(-maxAsteroidSpeed + static_cast <float> (rand()) /( static_cast <float> (RAND_MAX/(maxAsteroidSpeed*2.0f))),
                                                    -maxAsteroidSpeed + static_cast <float> (rand()) /( static_cast <float> (RAND_MAX/(maxAsteroidSpeed*2.0f)))));
        m_collisionMgr.addObject(&m_asteroids.back());
    }
    m_collisionMgr.refresh();
    return 0;
}

void ActiveSystem::update(float fTime)
{
    for(std::list<Asteroid>::iterator i = m_asteroids.begin(); i != m_asteroids.end();)
    {
        i->update(fTime);
        if(!m_borders.contains(i->getPosition()))
        {
            m_collisionMgr.removeObject(&(*i));
            m_asteroids.erase(i++);
        }
        else
            i++;
    }

    m_collisionMgr.update(fTime);

    while(m_asteroids.size() < m_minAsteroidCount)
    {
        float maxAsteroidSpeed = std::stof(getConstant("AsteroidMaxSpeed"));
        m_asteroids.emplace_back();
        m_asteroids.back().init(sf::Vector2f(m_borders.left + static_cast <float> (rand()) /( static_cast <float> (RAND_MAX/(m_borders.width))),
                                             m_borders.top + static_cast <float> (rand()) /( static_cast <float> (RAND_MAX/(m_borders.height)))));
        m_asteroids.back().setMovement(sf::Vector2f(-maxAsteroidSpeed + static_cast <float> (rand()) /( static_cast <float> (RAND_MAX/(maxAsteroidSpeed*2.0f))),
                                                    -maxAsteroidSpeed + static_cast <float> (rand()) /( static_cast <float> (RAND_MAX/(maxAsteroidSpeed*2.0f)))));
        m_collisionMgr.addObject(&m_asteroids.back());
    }
}

void ActiveSystem::render(sf::RenderTarget& screen)
{
    for(auto i : m_asteroids)
    {
        screen.draw(i);
    }
    m_collisionMgr.renderGrid(screen);
}

void ActiveSystem::exit()
{
    m_collisionMgr.exit();
    m_asteroids.clear();
}
