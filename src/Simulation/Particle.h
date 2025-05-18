#pragma once

#include <SFML/Graphics.hpp>
#include <vector>

#include "SimulationParams.h"


class Particle 
{
private:
    SimulationParams params_;

    sf::Vector2f position_;
    sf::Vector2f velocity_;

    double mass_;
    double radius_;

    sf::Color color_;

    sf::CircleShape shape_;

public:
    Particle(sf::Vector2f position, double mass, double radius, sf::Color color);

    // void update(float dt);

    sf::CircleShape& getShape();

    sf::Vector2f getPos();
    sf::Vector2f getVel();
    double getMass();
    double getRadius();


    void setSimulationParams(const SimulationParams& params);
    sf::Vector2f& setPos();
    sf::Vector2f& setVel();

};