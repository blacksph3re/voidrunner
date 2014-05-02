#include <iostream>
#include <SFML/Graphics.hpp>
#include "../h/CollisionObject.hpp"

using namespace std;

int main()
{
    std::cout << sizeof(sf::CircleShape) << "  " << sizeof(sf::RectangleShape) << std::endl;
    sf::RenderWindow window(sf::VideoMode(8000, 600), "Blablabla");
    while(window.isOpen() && !sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
        window.display();
    return 0;
}
