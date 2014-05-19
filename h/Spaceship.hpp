#ifndef SPACESHIP_H
#define SPACESHIP_H
#include "../h/CollisionObject.hpp"
#include "../h/Weapon.hpp"

class Spaceship : public CollisionObject
{
    private:
        sf::Vector2f m_acceleration;
        sf::Vector2f m_direction;

        float m_max_acceleration;
        float m_rotation_direction;
        float m_turn_angle;

        Weapon m_weapon;
    public:
        void turnLeft(float fTime);
        void turnRight(float fTime);
        void accelerateForward(float fTime);
        void accelerateBack(float fTime);


        CollisionObject::Shapes getShape() {return CIRCLE;}
        sf::FloatRect getBoundingBox() const {return getGlobalBounds();}

        void setAcceleration(sf::Vector2f val) {m_acceleration = val;}
        sf::Vector2f getAcceleration() {return m_acceleration;}

        void setDirection(sf::Vector2f val) {m_direction = val;}
        sf::Vector2f getDirection() {return m_direction;}

        void setMaxAcceleration(float val) {m_max_acceleration = val;}
        float getMaxAcceleration() {return m_max_acceleration;}

        void setRotationDirection(float val) {m_rotation_direction = val;}
        float getRotationDirection() {return m_rotation_direction;}

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
