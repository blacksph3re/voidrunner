#ifndef INGAMEMENU_HPP_INCLUDED
#define INGAMEMENU_HPP_INCLUDED

#include <SFML/Graphics.hpp>

class IngameMenu
{
private:
    float       m_frameTimeSum;
    int         m_frameSum;
    sf::Text    m_FPSText;
public:

    int init();
    void update(float fTime);
    void render(sf::RenderTarget& screen);
    void exit();

};

#endif // INGAMEMENU_HPP_INCLUDED
