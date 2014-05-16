#ifndef PLAYER_H
#define PLAYER_H
#include "../h/Spaceship.hpp"


class Player
{
    private:
        Spaceship m_spaceship;

    public:
        int init();
        void update(float fTime);
        void handle_event(sf::Event event);
        void render(sf::RenderWindow& screen);

        void setSpaceship(Spaceship val) {m_spaceship = val;}
        Spaceship &getSpaceship() {return m_spaceship;}

        Player() {};
        ~Player() {};

    protected:
};

#endif // PLAYER_H
