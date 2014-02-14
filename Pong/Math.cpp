#include "Math.h"

namespace Math
{
float dotProduct(const sf::Vector2f &lhs, const sf::Vector2f &rhs)
{
    return lhs.x * rhs.x + lhs.y * rhs.y;
}

sf::Vector2f reflection(const sf::Vector2f &vector, const sf::Vector2f &normal)
{
    return vector - 2 * dotProduct(vector, normal) * normal;
}

sf::Vector2f normalize(const sf::Vector2f &vector)
{
    float mag = magnitude(vector);

    if(mag == 0)
        return sf::Vector2f(0 , 0);
    else
        return sf::Vector2f(vector.x / mag, vector.y / mag);
}

float magnitude(const sf::Vector2f &vector)
{
    return sqrtf(vector.x * vector.x + vector.y * vector.y);
}
}
