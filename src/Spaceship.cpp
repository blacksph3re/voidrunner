#include "../h/Spaceship.hpp"
#include "../h/ResourceManager.hpp"
#include "../h/ConstantManager.hpp"

void Spaceship::init(std::string texture_name, sf::Vector2f position)
{
    setTexture(ResourceManager::get().getTexture(texture_name), true);
    setPosition(position);
    setMass(1);
}

void Spaceship::setMoveTarget(sf::Vector2f move_target) {

}

void Spaceship::update(float fTime)
{
    setMovement(m_acceleration * fTime + getMovement() * std::stof(getConstant("Drag")));
    move(getMovement());
}
