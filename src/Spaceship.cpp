#include <iostream>
#include <SFML/Graphics.hpp>
#include "../h/Spaceship.hpp"
#include "../h/ResourceManager.hpp"
#include "../h/ConstantManager.hpp"
#include "../h/VectorCalculator.hpp"


int Spaceship::init()
{
    setTexture(ResourceManager::get().getTexture("Spaceship"));
    setPosition(sf::Vector2f(0, 0));
    setMoveTarget( getPosition() );
    setMass(1);
    setMovement(sf::Vector2f(0, 0));
    setAcceleration(sf::Vector2f(0, 0));
    setMaxAcceleration(50);

    std::cout << "pos: " << getPosition().x << getPosition().y
              << "move: " << getMovement().x << getMovement().y
              << "acc: " << getAcceleration().x << getAcceleration().y
              << "\n";

    return 0;
    // Eine Änderung von Marcel
}

void Spaceship::update(float fTime)
{
    if ( getPosition().x != getMoveTarget().x || getPosition().y != getMoveTarget().y ) {
        if ( fTime * fTime != 0 ) {
            setAcceleration( 2.0f * ( getMoveTarget() - getPosition() - getMovement() * fTime ) / ( fTime * fTime ) );
        } else {
            std::cout << "frame-time square = 0" << "\n";
        }
        if ( VectorCalculator::get().length( getAcceleration() ) > getMaxAcceleration() )
            setAcceleration( VectorCalculator::get().setLength( getAcceleration(), getMaxAcceleration() ) );

    setMovement(getAcceleration() * fTime + getMovement() * std::stof(getConstant("Drag")));

    move(getMovement() * fTime);
    }

    std::cout << "[Spaceship] Pos: " << getPosition().x << " " << getPosition().y
              << " Tar: " << getMoveTarget().x << " " << getMoveTarget().y
              << " Move: " << getMovement().x << " " << getMovement().y
              << " Acc: " << getAcceleration().x << " " << getAcceleration().y
              << "\n";
}
