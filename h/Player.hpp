#ifndef PLAYER_H
#define PLAYER_H
#include "../h/Spaceship.hpp"


class Player
{
    private:
        Spaceship m_spaceship = Spaceship();

    public:
        void init();
        void update(float fTime);
        void handle_event(sf::Event event);

        Spaceship getSpaceship() {return m_spaceship;}

        Player() {};
        ~Player() {};

    protected:
};

#endif // PLAYER_H
