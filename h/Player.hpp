#ifndef PLAYER_H
#define PLAYER_H
#include "../h/Spaceship.hpp"


class Player
{
    private:
        Spaceship m_spaceship = Spaceship();

    public:
        int init();
        void update(float fTime);
        void handle_event(sf::Event event);
        void render(sf::RenderWindow& screen);

        Spaceship getSpaceship() {return m_spaceship;}

        Player() {};
        ~Player() {};

    protected:
};

#endif // PLAYER_H
