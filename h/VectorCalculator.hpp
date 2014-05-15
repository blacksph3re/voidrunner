#ifndef VECTORCALCULATOR_H
#define VECTORCALCULATOR_H

#include <SFML/Graphics.hpp>
#include <SFML/System/NonCopyable.hpp>

class VectorCalculator : sf::NonCopyable
{
    private:

    public:
        static VectorCalculator& get();

        float length(sf::Vector2f vec);
        sf::Vector2f setLength(sf::Vector2f vec, float len);

        VectorCalculator() {};
        ~VectorCalculator() {};
    protected:
};

#endif // VECTORCALCULATOR_H
