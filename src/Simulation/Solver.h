#pragma once

#include "Particle.h"
#include "SimulationParams.h"

#include <SFML/Graphics.hpp>
#include <vector>

#include "Math/vec.h"

class Solver 
{
private:
    std::vector<Particle> particles_;
    SimulationParams params_;

    void collideWithWall(Particle& particle, sf::Vector2u winSize);
    bool areColliding(Particle& a, Particle& b); // returns true if particles a and b collide

public:
    void setSimulationParams(const SimulationParams& params); // Pass the simulation parameters defined by SimulationControlPanel to the solver

    void addParticle(const Particle& particle); 
    void drawParticles(sf::RenderWindow& window);

    void handleCollision();

    void update(sf::Time dt, sf::Vector2u winSize);

    const std::vector<Particle>& getParticles(); // returns a reference to particles_
};