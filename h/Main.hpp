#ifndef MAIN_HPP_INCLUDED
#define MAIN_HPP_INCLUDED

#include <SFML/Graphics.hpp>
#include "../h/CollisionManager.hpp"

class Main
{
private:
    sf::RenderWindow    m_screen;
    bool                m_running;
    CollisionManager    m_colManager;

    int init();
    void update(float fTime);
    void render();
    void exit();
public:
    void run();

    Main();
    ~Main();
};

#endif // MAIN_HPP_INCLUDED
