#include <SFML/Graphics.hpp>
#include "../h/Spaceship.hpp"
#include "../h/ResourceManager.hpp"
#include "../h/ConstantManager.hpp"
#include "../h/VectorCalculator.hpp"


int Spaceship::init()
{
    setTexture(ResourceManager::get().getTexture("Spaceship"));
    setPosition(sf::Vector2f(0, 0));
    setMass(1);
    setMovement(sf::Vector2f(0, 0));
    setAcceleration(sf::Vector2f(1, 1));
    return 0;
}

void Spaceship::update(float fTime)
{
    setAcceleration(
        VectorCalculator::get().setLength2f(
            getMoveTarget() - getPosition(), 1
        )
    );

    setMovement(m_acceleration * fTime + getMovement() * std::stof(getConstant("Drag")));
    move(getMovement());

    printf("[Spaceship] Position: %f %f\n", getPosition().x, getPosition().y);

    /*
    near to move_target:
        get slower
    else:
        move faster
        (max speed through drag)
    */
}
