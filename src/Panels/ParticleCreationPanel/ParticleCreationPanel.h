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

    float getParticleMass(); // used to get the mass inputed by the user when creating a new particle 
    float getParticleRadius(); // used to get the radius inputed by the user when creating a new particle 

    sf::Color getParticleColor(); // used to get the color inputed by the user when creating a new particle 

    void render(); // rendering the panel
};