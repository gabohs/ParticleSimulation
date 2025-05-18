#pragma once

#include "Particle.h"
#include "SimulationParams.h"

#include <SFML/Graphics.hpp>
#include <vector>

class Solver 
{
private:
    std::vector<Particle> particles_;
    SimulationParams params_;

public:
    void setSimulationParams(const SimulationParams& params);

    void addParticle(const Particle& particle);
    void drawParticles(sf::RenderWindow& window);

    void update(sf::Time dt, sf::Vector2u winSize);

    const std::vector<Particle>& getParticles();
};