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
    setAcceleration(sf::Vector2f(100, 100));

    std::cout << "pos: " << getPosition().x << getPosition().y
              << "move: " << getMovement().x << getMovement().y
              << "acc: " << getAcceleration().x << getAcceleration().y
              << "\n";

    return 0;
}

void Spaceship::update(float fTime)
{
    setAcceleration(
        VectorCalculator::get().setLength2f(
            getMoveTarget() - getPosition() ,
            VectorCalculator::get().length2f( getAcceleration() )
        )
    );

    setMovement(getAcceleration() * fTime + getMovement() * std::stof(getConstant("Drag")));

    move(getMovement() * fTime);

    std::cout << "[Spaceship] Pos: " << getPosition().x << " " << getPosition().y
              << " Tar: " << getMoveTarget().x << " " << getMoveTarget().y
              << " Move: " << getMovement().x << " " << getMovement().y
              << " Acc: " << getAcceleration().x << " " << getAcceleration().y
              << "\n";

    /*
    near to move_target:
        get slower
    else:
        move faster
        (max speed through drag)
    */
}
