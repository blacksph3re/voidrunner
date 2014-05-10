#include "../h/VectorCalculator.hpp"
#include <math.h>
#include <SFML/Graphics.hpp>

VectorCalculator& VectorCalculator::get() {
    static VectorCalculator instance;
    return instance;
}

float VectorCalculator::length2f(sf::Vector2f vec) {
    return sqrt(vec.x * vec.x + vec.y * vec.y);
}

sf::Vector2f VectorCalculator::setLength2f(sf::Vector2f vec, float len) {
    return ((vec / VectorCalculator::get().length2f(vec)) * len);
}
