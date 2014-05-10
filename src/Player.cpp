#include <SFML/Graphics.hpp>
#include "../h/Player.hpp"

int Player::init() {
    int retval;

    return retval = m_spaceship.init();
}

void Player::update(float fTime) {
    m_spaceship.update(fTime);
}

void Player::render(sf::RenderWindow& screen) {
    screen.draw(m_spaceship);
}

void Player::handle_event(sf::Event event) {
    if (event.type == sf::Event::MouseButtonPressed && event.mouseButton.button == sf::Mouse::Left) {
        m_spaceship.setMoveTarget(sf::Vector2f(sf::Mouse::getPosition()));
    }
}
