#include <iostream>
#include <cstdlib>
#include <ctime>
#include <string>
#include "../h/Main.hpp"
#include "../h/ConstantManager.hpp"
#include "../h/ResourceManager.hpp"

int main()
{
    srand (static_cast <unsigned> (time(0)));
    Main::get().run();
    return 0;
}

Main& Main::get()
{
    static Main instance;
    return instance;
}

Main::Main()
{}

Main::~Main()
{}

void Main::run()
{
    if(init() != 0)
    {
        std::cerr << "Init failed" << std::endl;
        return;
    }

    m_running = true;
    float frameTime = 0.0f;
    sf::Clock clock;
    while(m_running && m_screen.isOpen())
    {
        clock.restart();
        sf::Event event;
        while (m_screen.pollEvent(event))
        {
            // "close requested" event: we close the window
            if (event.type == sf::Event::Closed)
                m_screen.close();
            if(event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Escape)
                m_screen.close();
            m_player.handle_event(event);
        }

        render();
        update(frameTime);

        frameTime = clock.getElapsedTime().asSeconds();
    }

    exit();
}

int Main::init()
{
    int retval;

    retval = ResourceManager::get().init();
    if(retval != 0)
        return retval;

    retval = ConstantManager::get().init();
    if(retval != 0)
        return retval;

    retval = m_space.init();
    if(retval != 0)
        return retval;

    retval = m_ingameMenu.init();
    if(retval != 0)
        return retval;

    retval = m_player.init();
    if (retval != 0)
        return retval;

    m_screen.create(sf::VideoMode(1920, 1080), "Voidrunner");
    m_menuView = sf::View(sf::FloatRect(0, 0, std::stof(getConstant("MenuViewWidth")), std::stof(getConstant("MenuViewHeight"))));
    m_ingameView = sf::View(sf::FloatRect(-1200, -1200, 2400, 2400));
    return 0;
}

void Main::exit()
{
    m_screen.close();
    m_space.exit();
    m_ingameMenu.exit();
    ResourceManager::get().exit();
}

void Main::update(float fTime)
{
    m_space.update(fTime);
    m_ingameMenu.update(fTime);
    m_player.update(fTime);
}

void Main::render()
{
    m_screen.clear();
    m_screen.setView(m_ingameView);
    m_space.render(m_screen);
    m_player.render(m_screen);
    m_screen.setView(m_menuView);
    m_ingameMenu.render(m_screen);
    m_screen.display();
}

sf::Vector2f Main::getIngameCursor()
{
    return m_screen.mapPixelToCoords(sf::Mouse::getPosition(m_screen), m_ingameView);
}

sf::Vector2f Main::getMenuCursor()
{
    return m_screen.mapPixelToCoords(sf::Mouse::getPosition(m_screen), m_menuView);
}
