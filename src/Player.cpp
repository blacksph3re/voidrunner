#include "../h/Player.hpp"

void Player::init() {
    m_spaceship = Spaceship();
}

void Player::update(float fTime) {
    m_spaceship.update(fTime);
}

void Player::handle_event(sf::Event event) {
    if (event.type == sf::Event::MouseButtonPressed && event.mouseButton.button == sf::Mouse::Left) {
        m_spaceship.setMoveTarget(sf::Vector2f(sf::Mouse::getPosition()));
    }
}
