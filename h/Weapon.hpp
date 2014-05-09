#ifndef WEAPON_H
#define WEAPON_H

#include <SFML/Graphics.hpp>

class Weapon : public sf::Sprite
{
    public:

        void update(float fTime);

        Weapon() {};
        ~Weapon() {};
    protected:
    private:
        float m_reload_time;
        float m_max_reload_time;
};

#endif // WEAPON_H
