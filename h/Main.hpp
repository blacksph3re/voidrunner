#ifndef MAIN_HPP_INCLUDED
#define MAIN_HPP_INCLUDED

#include <SFML/Graphics.hpp>
#include "Space.hpp"

class Main
{
private:
    sf::RenderWindow    m_screen;
    bool                m_running;
    Space               m_space;

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
