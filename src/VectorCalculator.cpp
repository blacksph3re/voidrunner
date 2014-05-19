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

    float DegToRad(float deg) {
        return deg / 180 * M_PI;
    }

    float RadToDeg(float rad) {
        return rad / M_PI * 180;
    }

    sf::Vector2f rotateVectorRad(sf::Vector2f vec, float angle) {
        if (vec.x == 0 && vec.y == 0) {
            return sf::Vector2f(0, 0);
        } else {
            return sf::Vector2f(vec.x * cos(angle) - vec.y * sin(angle), vec.x * sin(angle) + vec.y * cos(angle));
        }
    }

    sf::Vector2f rotateVectorDeg(sf::Vector2f vec, float angle) {
        if (vec.x == 0 && vec.y == 0) {
            return sf::Vector2f(0, 0);
        } else {
            angle = RadToDeg( angle );
            return sf::Vector2f(vec.x * cos(angle) - vec.y * sin(angle), vec.x * sin(angle) + vec.y * cos(angle));
        }
    }

    float VectorToRoationDeg( sf::Vector2f vec ) {
        return  RadToDeg( ( atan2( vec.y, vec.x ) - atan2( 0, -1 ) ) );
    }

    sf::Vector2f AngleDegToVector( float angle ) {
        sf::Vector2f vec = sf::Vector2f( 1 , 0 );
        return VectorCalculator::rotateVectorDeg( vec , angle );
    }

    float AngleDegBetweenVectors( sf::Vector2f vec1, sf::Vector2f vec2 ) {
        return RadToDeg( ( atan2( vec1.y, vec1.x ) - atan2( vec2.y, vec2.x ) ) );
    }

}
