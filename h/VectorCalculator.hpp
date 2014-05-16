#ifndef VECTORCALCULATOR_H
#define VECTORCALCULATOR_H

#include <SFML/Graphics.hpp>
#include <SFML/System/NonCopyable.hpp>

namespace VectorCalculator {

    float length(sf::Vector2f vec);
    sf::Vector2f setLength(sf::Vector2f vec, float len);

    sf::Vector2f rotateVector(sf::Vector2f vec, float angle);

    float VectorToRoationDeg( sf::Vector2f vec );
    sf::Vector2f RotationDegToVector( float rot );

};

#endif // VECTORCALCULATOR_H
