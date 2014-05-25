#include <iostream>
#include <SFML/Graphics.hpp>
#include "../h/Spaceship.hpp"
#include "../h/ResourceManager.hpp"
#include "../h/ConstantManager.hpp"
#include "../h/VectorCalculator.hpp"


int Spaceship::init() {
    setTexture( ResourceManager::get().getTexture( "Spaceship" ) );
    setPosition(sf::Vector2f(0, 0) );
    setOrigin( getLocalBounds().width / 2.0f , getLocalBounds().height / 2.0f );
    setMass( 1 );
    setMovement( sf::Vector2f(0, 0) );
    setAcceleration( 100 );
    setTurnAngle( 10 );

    return 0;
}

void Spaceship::update(float fTime) {
    setMovement(
        VectorCalculator::setLength(
            VectorCalculator::AngleDegToVector( getRotation() ) ,
            VectorCalculator::length( getMovement() ) * std::stof(getConstant("Drag"))
        )
    );

    move(getMovement() * fTime);
}

void Spaceship::turnLeft( float fTime ) {
    rotate( - getTurnAngle() * fTime );
}

void Spaceship::turnRight( float fTime ) {
    rotate( getTurnAngle() * fTime );
}

void Spaceship::accelerateForward( float fTime ) {
    sf::Vector2f acceleration = VectorCalculator::setLength(
        VectorCalculator::AngleDegToVector( getRotation() ) , getAcceleration() );
    setMovement( getMovement() + acceleration * fTime );
}

void Spaceship::accelerateBack( float fTime ) {
    sf::Vector2f acceleration = VectorCalculator::setLength(
        VectorCalculator::AngleDegToVector( getRotation() ) , getAcceleration() );
    setMovement( getMovement() - acceleration * fTime );
}
