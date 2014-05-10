#ifndef MAIN_HPP_INCLUDED
#define MAIN_HPP_INCLUDED

#include <SFML/Graphics.hpp>
#include "Space.hpp"
#include "IngameMenu.hpp"
#include "Player.hpp"

class Main : public sf::NonCopyable
{
private:
    sf::RenderWindow    m_screen;
    bool                m_running;

    Space               m_space;
    IngameMenu          m_ingameMenu;
    Player              m_player;

    sf::View            m_ingameView;
    sf::View            m_menuView;

    int init();
    void update(float fTime);
    void render();
    void exit();
public:
    void run(); // to be called only by main()

    Main();
    ~Main();
};

#endif // MAIN_HPP_INCLUDED
