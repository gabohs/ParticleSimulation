#pragma once

#include <SFML/Graphics.hpp>

class ParticleCreationPanel
{
private:
    // particle attributes
    double particleMass_;
    double particleRadius_;

    sf::Color color_;

public:
    ParticleCreationPanel();

    double getParticleMass();
    double getParticleRadius();

    sf::Color getParticleColor();

    void update();
};