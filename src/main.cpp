#include <iostream>
#include <SFML/Graphics.hpp>

using namespace std;

int main()
{
    sf::RenderWindow window(sf::VideoMode(8000, 600), "Blablabla");
    while(window.isOpen() && !sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
        window.display();
    return 0;
}
