#pragma once

#include <SFML/Graphics.hpp>

namespace math  
{   
    sf::Vector2f vecSubtract(sf::Vector2f& vec1, sf::Vector2f& vec2);
    sf::Vector2f vecAdd(sf::Vector2f& vec1, sf::Vector2f& vec2);
    sf::Vector2f vecMultiply(sf::Vector2f& v, float scalar);

    sf::Vector2f vecProjection(sf::Vector2f& vec1, sf::Vector2f& vec2);

    sf::Vector2f vecNormalize(sf::Vector2f& vec);

    float vecLength(sf::Vector2f& vec);
}