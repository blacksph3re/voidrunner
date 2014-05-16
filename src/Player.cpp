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
        getSpaceship().setAcceleration( VectorCalculator::setLength( getSpaceship().getDirection() , getSpaceship().getMaxAcceleration() ) );
    } else if (sf::Keyboard::isKeyPressed(sf::Keyboard::S)) {
        getSpaceship().setAcceleration( VectorCalculator::setLength( getSpaceship().getDirection() , - getSpaceship().getMaxAcceleration() ) );
    } else {
        getSpaceship().setAcceleration( sf::Vector2f( 0, 0 ) );
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)) {
        getSpaceship().setAcceleration( VectorCalculator::rotateVector( getSpaceship().getAcceleration(), -2 ) );
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)) {
        getSpaceship().setAcceleration( VectorCalculator::rotateVector( getSpaceship().getAcceleration(), 2 ) );
    }


    getSpaceship().update(fTime);
}

void Player::render(sf::RenderWindow& screen) {
    screen.draw(m_spaceship);
}

void Player::handle_event(sf::Event event) {
}
