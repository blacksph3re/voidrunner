#include <iostream>
#include <SFML/Graphics.hpp>
#include "../h/Spaceship.hpp"
#include "../h/ResourceManager.hpp"
#include "../h/ConstantManager.hpp"
#include "../h/VectorCalculator.hpp"


int Spaceship::init() {
    setTexture( ResourceManager::get().getTexture( "Spaceship" ) );
    setPosition(sf::Vector2f(0, 0) );
    setDirection( sf::Vector2f(0, -1) );
    setRotationDirection( 0.0f );
    setMass( 1 );
    setMovement( sf::Vector2f(0, 0) );
    setAcceleration( sf::Vector2f(0, 0) );
    setMaxAcceleration( 100 );
    setTurnAngle( 10 );

    std::cout << "pos: " << getPosition().x << getPosition().y
              << "move: " << getMovement().x << getMovement().y
              << "acc: " << getAcceleration().x << getAcceleration().y
              << "\n";

    return 0;
}

void Spaceship::update(float fTime) {
    setMovement(getAcceleration() * fTime + getMovement() * std::stof(getConstant("Drag")));

    rotate( getTurnAngle() * getRotationDirection() * fTime );

    move(getMovement() * fTime);
}

void Spaceship::turnLeft() {
    setRotationDirection( -1.0f );
}

void Spaceship::turnRight() {
    setRotationDirection( 1.0f );
}

void Spaceship::stopTurning() {
    setRotationDirection( 0.0f );
}

void Spaceship::accelerateForward() {
    setAcceleration( VectorCalculator::setLength( VectorCalculator::AngleDegToVector( getRotation() ) , getMaxAcceleration() ) );
}

void Spaceship::accelerateBack() {
    setAcceleration( - VectorCalculator::setLength( - VectorCalculator::AngleDegToVector( getRotation() ) , getMaxAcceleration() ) );
}

void Spaceship::stopAcceleration() {
    setAcceleration( sf::Vector2f( 0, 0 ) );
}
