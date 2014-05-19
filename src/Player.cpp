#include <iostream>
#include <SFML/Graphics.hpp>
#include "../h/Main.hpp"
#include "../h/Player.hpp"
#include "../h/VectorCalculator.hpp"

int Player::init() {
    setSpaceship( Spaceship() );
    return m_spaceship.init();
}

void Player::update(float fTime) {
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::W)) {
        getSpaceship().accelerateForward( fTime );
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::S)) {
        getSpaceship().accelerateBack( fTime );
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)) {
        getSpaceship().turnLeft( fTime );
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)) {
        getSpaceship().turnRight( fTime );
    }

    getSpaceship().update(fTime);
}

void Player::render(sf::RenderWindow& screen) {
    screen.draw(m_spaceship);
}

void Player::handle_event(sf::Event event) {
}
