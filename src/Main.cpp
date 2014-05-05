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
    Main m;
    m.run();
    return 0;
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

    retval += m_space.init();
    if(retval != 0)
        return retval;

    m_screen.create(sf::VideoMode(800, 600), "Voidrunner");
    m_screen.setView(sf::View(sf::FloatRect(-1200, -1200, 2400, 2400)));
    return 0;
}

void Main::exit()
{
    m_space.exit();
    ResourceManager::get().exit();
}

void Main::update(float fTime)
{
    m_space.update(fTime);
}

void Main::render()
{
    m_screen.clear();
    m_space.render(m_screen);
    m_screen.display();
}

