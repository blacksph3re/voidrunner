#include <iostream>
#include "../h/VectorCalculator.hpp"
#define _USE_MATH_DEFINES
#include <math.h>
#include <SFML/Graphics.hpp>


namespace VectorCalculator {

    float length(sf::Vector2f vec) {
        return sqrt(vec.x * vec.x + vec.y * vec.y);
    }

    sf::Vector2f setLength(sf::Vector2f vec, float len) {
        sf::Vector2f norm;
        if (vec.x == 0 && vec.y == 0)
            return norm = sf::Vector2f(len, len);
        else {
            return norm = (vec * len) / VectorCalculator::length(vec);
        }
    }

    sf::Vector2f rotateVector(sf::Vector2f vec, float angle) {
        return sf::Vector2f(vec.x * cos(angle) - vec.y * sin(angle), vec.x * sin(angle) + vec.y * cos(angle));
    }

    float VectorToRoationDeg( sf::Vector2f vec ) {
        return ( atan2( vec.y, vec.x ) - atan2( 0, -1 ) ) / 180.0f * M_PI;
    }

    sf::Vector2f RotationDegToVector( float rot ) {
        return sf::Vector2f(0, 0);
    }

}
