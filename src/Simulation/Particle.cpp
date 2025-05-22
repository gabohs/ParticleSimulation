#include "Particle.h"

Particle::Particle(sf::Vector2f position, float mass, float radius, sf::Color color) : 
    position_(position), mass_(mass), radius_(radius), color_(color)
{
    shape_.setPosition(position_);
    shape_.setRadius(radius_);

    shape_.setFillColor(color_);
}


sf::CircleShape& Particle::getShape()
{
    return shape_;
}

sf::Vector2f Particle::getPos() const
{
    return position_;
}

sf::Vector2f Particle::getVel() const
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

void Particle::setPos(sf::Vector2f& pos)
{
    position_ = pos;

    shape_.setPosition(position_);
}
    
    void Particle::setVel(sf::Vector2f &vel)
    {
        velocity_= vel;
    }


