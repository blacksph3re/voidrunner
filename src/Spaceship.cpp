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
    setMovement( getMovement() * std::stof(getConstant("Drag")) );
    move(getMovement() * fTime);
}

void Spaceship::turnLeft( float fTime ) {
    rotate( - getTurnAngle() * fTime );
}

void Spaceship::turnRight( float fTime ) {
    rotate( getTurnAngle() * fTime );
}

void Spaceship::accelerateForward( float fTime ) {
    sf::Vector2f acceleration = VectorCalculator::setLength( VectorCalculator::AngleDegToVector( getRotation() ) , getMaxAcceleration() * fTime );
    setMovement( getMovement() + acceleration );
}

void Spaceship::accelerateBack( float fTime ) {
    sf::Vector2f acceleration = VectorCalculator::setLength( VectorCalculator::AngleDegToVector( getRotation() ) , getMaxAcceleration() * fTime );
    setMovement( getMovement() - acceleration );
}
