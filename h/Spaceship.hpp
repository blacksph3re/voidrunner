#ifndef SPACESHIP_H
#define SPACESHIP_H
#include "../h/CollisionObject.hpp"
#include "../h/Weapon.hpp"

class Spaceship : public CollisionObject
{
    private:
        sf::Vector2f m_acceleration;
        Weapon m_weapon;
    public:
        CollisionObject::Shapes getShape() {return CIRCLE;}
        sf::FloatRect getBoundingBox() const {return getGlobalBounds();}

        void setAcceleration(sf::Vector2f val) {m_acceleration = val;}
        sf::Vector2f getAcceleration() {return m_acceleration;}

        void setMoveTarget(sf::Vector2f move_target);

        void init(std::string texture, sf::Vector2f position);
        void update(float fTime);
        // void draw();

        Spaceship() {};
        ~Spaceship() {};
    protected:

};

#endif // SPACESHIP_H
