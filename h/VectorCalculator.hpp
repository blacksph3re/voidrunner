#ifndef VECTORCALCULATOR_H
#define VECTORCALCULATOR_H

#include <SFML/Graphics.hpp>
#include <SFML/System/NonCopyable.hpp>

namespace VectorCalculator {

    float length(sf::Vector2f vec);
    sf::Vector2f setLength(sf::Vector2f vec, float len);

    float RadToDeg(float rad);
    float DegToRad(float deg);

    sf::Vector2f rotateVectorRad(sf::Vector2f vec, float angle);
    sf::Vector2f rotateVectorDeg(sf::Vector2f vec, float angle);

    float VectorToRoationDeg( sf::Vector2f vec );
    sf::Vector2f AngleDegToVector( float angle );

    float AngleDegBetweenVectors( sf::Vector2f vec1, sf::Vector2f vec2 );

};

#endif // VECTORCALCULATOR_H
