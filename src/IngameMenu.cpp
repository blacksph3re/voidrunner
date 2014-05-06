#include "../h/IngameMenu.hpp"
#include "../h/ResourceManager.hpp"
#include <string>

int IngameMenu::init()
{
    m_frameTimeSum = 0;
    m_frameSum = 0;
    m_FPSText.setFont(ResourceManager::get().getFont("default"));
    m_FPSText.setCharacterSize(40);
    m_FPSText.setColor(sf::Color::Red);
    m_FPSText.setString("");
    return 0;
}

void IngameMenu::update(float fTime)
{
    m_frameTimeSum += fTime;
    m_frameSum++;
    if(m_frameTimeSum >= 1)
    {
        m_frameTimeSum -= 1;
        std::string text = "FPS: " + std::to_string(m_frameSum);
        m_FPSText.setString(text);
        m_frameSum = 0;
    }
}

void IngameMenu::render(sf::RenderTarget& screen)
{
    screen.draw(m_FPSText);
}

void IngameMenu::exit()
{
}
