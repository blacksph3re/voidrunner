#include <iostream>
#include "../h/VectorCalculator.hpp"
#include <math.h>
#include <SFML/Graphics.hpp>

VectorCalculator& VectorCalculator::get() {
    static VectorCalculator instance;
    return instance;
}

float VectorCalculator::length2f(sf::Vector2f vec) {
    //std::cout << "len" << vec.x << " " << vec.y << "\n";
    return sqrt(vec.x * vec.x + vec.y * vec.y);
}

sf::Vector2f VectorCalculator::setLength2f(sf::Vector2f vec, float len) {
    //std::cout << "set len" << vec.x << " " << vec.y << " " << len << "\n";
    sf::Vector2f norm;
    if (vec.x == 0 && vec.y == 0)
        return norm = sf::Vector2f(len, len);
    else {
        return norm = (vec * len) / VectorCalculator::get().length2f(vec);
    }
 }
