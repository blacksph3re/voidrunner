#include <iostream>
#include <SFML/Graphics.hpp>
#include "../h/Player.hpp"

int Player::init() {
    return m_spaceship.init();
}

void Player::update(float fTime) {
    m_spaceship.update(fTime);
}

void Player::render(sf::RenderWindow& screen) {
    screen.draw(m_spaceship);
}

void Player::handle_event(sf::Event event) {
    if (event.type == sf::Event::MouseButtonPressed && event.mouseButton.button == sf::Mouse::Left) {
        sf::Vector2f mouse_pos = sf::Vector2f( sf::Mouse::getPosition() );
        getSpaceship().setMoveTarget( mouse_pos );
        std::cout << "mouse_pos: " << mouse_pos.x << " " << mouse_pos.y << "\n";
    }
}
