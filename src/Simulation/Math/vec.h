#pragma once

#include <SFML/Graphics.hpp>

namespace math  
{   
    sf::Vector2f vecSubtract(const sf::Vector2f& vec1, const sf::Vector2f& vec2);
    sf::Vector2f vecAdd(const sf::Vector2f& vec1, const sf::Vector2f& vec2);
    sf::Vector2f vecMultiply(const sf::Vector2f& v, float scalar);

    sf::Vector2f vecProjection(const sf::Vector2f& vec1, const sf::Vector2f& vec2);

    sf::Vector2f vecNormalize(const sf::Vector2f& vec);

    float vecLength(const sf::Vector2f& vec);
}