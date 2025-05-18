#pragma once

#include <SFML/Graphics.hpp>

class ParticleCreationPanel
{
private:
    // particle attributes
    float particleMass_;
    float particleRadius_;

    sf::Color color_;

public:
    ParticleCreationPanel();

    float getParticleMass();
    float getParticleRadius();

    sf::Color getParticleColor();

    void update();
};