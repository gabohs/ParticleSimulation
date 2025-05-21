#include "vec.h"

namespace math
{   
    sf::Vector2f vecSubtract(const sf::Vector2f& vec1, const sf::Vector2f& vec2)
    {
        return sf::Vector2f(vec1.x - vec2.x, vec1.y - vec2.y);
    }

    sf::Vector2f vecAdd(const sf::Vector2f &vec1, const sf::Vector2f &vec2)
    {
        return sf::Vector2f(vec1.x + vec2.x, vec1.y + vec2.y);
    }

    sf::Vector2f vecMultiply(const sf::Vector2f &v, float scalar)
    {
        return sf::Vector2f(v.x * scalar, v.y * scalar);;
    }

    sf::Vector2f vecProjection(const sf::Vector2f& vec1, const sf::Vector2f& vec2)
    {
        float dot = ( vec1.x * vec2.x ) + ( vec1.y * vec2.y);
        float magSquared = ( vec2.x * vec2.x) + ( vec2.y * vec2.y );

        if (magSquared == 0.0f) 
            return sf::Vector2f(0.0f, 0.0f);

        float scale = dot / magSquared;

        return sf::Vector2f(vec2.x * scale, vec2.y * scale);
    }

    sf::Vector2f vecNormalize(const sf::Vector2f &vec)
    {
        float magnitude = std::sqrt( (vec.x * vec.x) + (vec.y * vec.y) );
        if (magnitude > 0.0f)
        {
            return sf::Vector2f(vec.x / magnitude, vec.y / magnitude);
        }
        return vec;
    }

    float vecLength(const sf::Vector2f &vec)
    {
        return std::sqrt(vec.x * vec.x + vec.y * vec.y);;
    }
}
