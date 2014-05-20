#ifndef SPACESHIP_H
#define SPACESHIP_H
#include "../h/CollisionObject.hpp"
#include "../h/Weapon.hpp"

class Spaceship : public CollisionObject
{
    private:
        float m_acceleration;
        float m_turn_angle;

        Weapon m_weapon;
    public:
        void turnLeft(float fTime);
        void turnRight(float fTime);
        void accelerateForward(float fTime);
        void accelerateBack(float fTime);


        CollisionObject::Shapes getShape() {return CIRCLE;}
        sf::FloatRect getBoundingBox() const {return getGlobalBounds();}

        void setAcceleration(float val) {m_acceleration = val;}
        float getAcceleration() {return m_acceleration;}

        void setTurnAngle(float val) {m_turn_angle = val;}
        float getTurnAngle() {return m_turn_angle;}

        int init();
        void update(float fTime);
        // void draw();

        Spaceship() {};
        ~Spaceship() {};
    protected:

};

#endif // SPACESHIP_H
