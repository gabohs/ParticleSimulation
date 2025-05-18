#include "Particle.h"

Particle::Particle(sf::Vector2f position, double mass, double radius, sf::Color color)
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

double Particle::getMass()
{
    return mass_;
}

double Particle::getRadius()
{
    return radius_;
}

void Particle::setSimulationParams(const SimulationParams &params)
{
    params_ = params;
}

sf::Vector2f& Particle::setPos()
{
    return position_;
}

sf::Vector2f& Particle::setVel()
{
    return velocity_;
}


