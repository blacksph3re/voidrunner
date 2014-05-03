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
        return;

    m_running = true;
    float frameTime = 0.0f;
    while(m_running && m_screen.isOpen())
    {
        sf::Clock clock;
        sf::Event event;
        while (m_screen.pollEvent(event))
        {
            // "close requested" event: we close the window
            if (event.type == sf::Event::Closed)
                m_screen.close();
        }

        update(frameTime);
        render();
        frameTime = clock.getElapsedTime().asSeconds();
    }

    exit();
}

int Main::init()
{
    int retval = 0;
    retval += ConstantManager::get().init();
    retval += m_colManager.init(sf::FloatRect(std::stof(getConstant("SystemSizeX")) * -0.5f,
                                              std::stof(getConstant("SystemSizeY")) * -0.5f,
                                              std::stof(getConstant("SystemSizeX")),
                                              std::stof(getConstant("SystemSizeY"))));

    m_screen.create(sf::VideoMode(800, 600), "Voidrunner");

    return retval;
}

void Main::exit()
{
}

void Main::update(float fTime)
{
    m_colManager.update(fTime);
}

void Main::render()
{
    m_screen.clear();


    m_screen.display();
}

