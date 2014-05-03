#include "../h/ActiveSystem.hpp"
#include "../h/ConstantManager.hpp"

int ActiveSystem::init(const InactiveSystem& data)
{
    m_borders.width = std::stof(getConstant("SystemSizeX"));
    m_borders.height = std::stof(getConstant("SystemSizeY"));
    m_borders.left = m_borders.width * -0.5f;
    m_borders.top = m_borders.height * -0.5f;

    if(m_colMgr.init(m_borders) != 0)
        return 1;



    return 0;
}

void ActiveSystem::update(float fTime)
{

}

void ActiveSystem::render(sf::RenderTarget& screen)
{

}

void ActiveSystem::exit()
{
    m_colMgr.exit();
}
