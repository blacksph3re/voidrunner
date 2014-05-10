#ifndef SPACESHIP_H
#define SPACESHIP_H
#include "../h/CollisionObject.hpp"
#include "../h/Weapon.hpp"

class Spaceship : public CollisionObject
{
    private:
        sf::Vector2f m_acceleration;
        sf::Vector2f m_move_target;

        Weapon m_weapon;
    public:
        CollisionObject::Shapes getShape() {return CIRCLE;}
        sf::FloatRect getBoundingBox() const {return getGlobalBounds();}

        void setAcceleration(sf::Vector2f val) {m_acceleration = val;}
        sf::Vector2f getAcceleration() {return m_acceleration;}

        void setMoveTarget(sf::Vector2f move_target) {m_move_target = move_target;}
        sf::Vector2f getMoveTarget() {return m_move_target;}

        int init();
        void update(float fTime);
        // void draw();

        Spaceship() {};
        ~Spaceship() {};
    protected:

};

#endif // SPACESHIP_H
