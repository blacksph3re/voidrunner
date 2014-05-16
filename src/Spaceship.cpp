#include <iostream>
#include <SFML/Graphics.hpp>
#include "../h/Spaceship.hpp"
#include "../h/ResourceManager.hpp"
#include "../h/ConstantManager.hpp"
#include "../h/VectorCalculator.hpp"


int Spaceship::init()
{
    setTexture( ResourceManager::get().getTexture( "Spaceship" ) );
    setPosition(sf::Vector2f(0, 0) );
    setDirection( sf::Vector2f(0, -1) );
    setMass( 1 );
    setMovement( sf::Vector2f(0, 0) );
    setAcceleration( sf::Vector2f(0, 0) );
    setMaxAcceleration( 50 );

    std::cout << "pos: " << getPosition().x << getPosition().y
              << "move: " << getMovement().x << getMovement().y
              << "acc: " << getAcceleration().x << getAcceleration().y
              << "\n";

    return 0;
}

void Spaceship::update(float fTime)
{
    setMovement(getAcceleration() * fTime + getMovement() * std::stof(getConstant("Drag")));

    setDirection( getAcceleration() );
    setRotation( VectorCalculator::VectorToRoationDeg( getDirection() ) );

    move(getMovement() * fTime);

    /*
    std::cout << "[Spaceship] Pos: " << getPosition().x << " " << getPosition().y
              << " Move: " << getMovement().x << " " << getMovement().y
              << " Acc: " << getAcceleration().x << " " << getAcceleration().y
              << "\n";
    */
}
