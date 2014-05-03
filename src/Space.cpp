#include "../h/Space.hpp"
#include "../h/ConstantManager.hpp"

int Space::init()
{
    int xResolution = std::stoi(getConstant("SystemCountX"));
    int yResolution = std::stoi(getConstant("SystemCountY"));
    m_inactiveSystems.clear();
    for(int x = 0; x < xResolution; x++)
    {
        m_inactiveSystems.emplace_back();
        for(int y = 0; y < yResolution; y++)
        {
            m_inactiveSystems.back().emplace_back();
            m_inactiveSystems.back().back().init();
        }
    }

    m_activeIndex.x = static_cast<std::size_t>(std::stoi(getConstant("DefaultSystemX")));
    m_activeIndex.y = static_cast<std::size_t>(std::stoi(getConstant("DefaultSystemY")));

    m_activeSystem.init(m_inactiveSystems[m_activeIndex.x][m_activeIndex.y]);
    m_inactiveUpdateTimer = 0;
    m_inactiveUpdateDelay = std::stof(getConstant("InactiveSystemUpdateDelay"));

    return 0;
}

void Space::update(float fTime)
{
    m_inactiveUpdateTimer -= fTime;
    if(m_inactiveUpdateTimer <= 0)
    {
        m_inactiveUpdateTimer += m_inactiveUpdateDelay;
        for(auto x : m_inactiveSystems)
        {
            for(auto y : x)
            {
                y.update(m_inactiveUpdateDelay);
            }
        }
    }

    m_activeSystem.update(fTime);
}

void Space::render(sf::RenderTarget& screen)
{
    m_activeSystem.render(screen);
}

void Space::exit()
{
    m_activeSystem.exit();
    for(auto x : m_inactiveSystems)
    {
        for(auto y : x)
        {
            y.exit();
        }
    }
    m_inactiveSystems.clear();
}
