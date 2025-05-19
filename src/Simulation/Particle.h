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

    // void update(float dt);

    sf::CircleShape& getShape();

    sf::Vector2f getPos();
    sf::Vector2f getVel();
    float getMass();
    float getRadius();    

    void setPos(sf::Vector2f& pos);
    void setVel(sf::Vector2f &vel);

    void collideWithWall(sf::Vector2u winSize, float restitution); // detects collision with walls

};