#pragma once

#include <SFML/Graphics.hpp>
#include <vector>

#include "SimulationParams.h"


class Particle 
{
private:
    sf::Vector2f position_;
    sf::Vector2f velocity_;

    float mass_;
    float radius_;

    sf::Color color_;

    sf::CircleShape shape_;

public:
    Particle(sf::Vector2f position, float mass, float radius, sf::Color color);

    sf::CircleShape& getShape(); // used to draw the sf::CircleShape in window.draw()

    sf::Vector2f getPos() const;
    sf::Vector2f getVel() const;
    float getMass() const;
    float getRadius() const;    

    void setPos(sf::Vector2f& pos);
    void setVel(sf::Vector2f &vel);
};