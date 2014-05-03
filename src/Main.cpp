#include <iostream>
#include <string>
#include "../h/Main.hpp"
#include "../h/ConstantManager.hpp"

int main()
{
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
        std::cout << "Init failed" << std::endl;
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
    int retval = 0;
    retval += ConstantManager::get().init();
    retval += m_space.init();

    m_screen.create(sf::VideoMode(800, 600), "Voidrunner");

    return retval;
}

void Main::exit()
{
    m_space.exit();
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

