#include <cmath>
#include <SFML/System/Vector2.hpp>

namespace Math
{
float dotProduct(const sf::Vector2f &lhs, const sf::Vector2f &rhs);
sf::Vector2f reflection(const sf::Vector2f &vector, const sf::Vector2f &normal);
sf::Vector2f normalize(const sf::Vector2f &vector);
float magnitude(const sf::Vector2f &vector) ;
}
