#include "Particle.h"

Particle::Particle(sf::Vector2f position, float mass, float radius, sf::Color color)
{
    position_ = position;
    mass_ = mass;
    radius_ = radius;
    color_ = color;

    shape_.setPosition(position_);
    shape_.setRadius(radius_);

    shape_.setFillColor(color_);
}


sf::CircleShape& Particle::getShape()
{
    return shape_;
}

sf::Vector2f Particle::getPos()
{
    return position_;
}

sf::Vector2f Particle::getVel()
{
    return velocity_;
}

float Particle::getMass()
{
    return mass_;
}

float Particle::getRadius()
{
    return radius_;
}

void Particle::setSimulationParams(const SimulationParams &params)
{
    params_ = params;
}

// sf::Vector2f& Particle::setPos()
// {
//     return position_;
// }

// sf::Vector2f& Particle::setVel()
// {
//     return velocity_;
// }

void Particle::setPos(sf::Vector2f& pos)
{
    position_ = pos;

    shape_.setPosition(position_);
}
    
void Particle::setVel(sf::Vector2f &vel)
{
    velocity_= vel;
}

void Particle::collideWithWall(sf::Vector2u winSize)
{
    sf::Vector2f windowSize(static_cast<float>(winSize.x), static_cast<float>(winSize.y));

    // Left and Right
    if (position_.x < 0.0f)
    {
        velocity_.x *= -1;
    }
    else if ( (position_.x + radius_) > windowSize.x )
    {
        velocity_.x *= -1;
    }

    // Top and Bottom
    if (position_.y < 0.0f)
    {
        velocity_.y *= -1;
    }
    else if ( (position_.y + radius_) > windowSize.y )
    {
        velocity_.y *= -1;
    }
}

