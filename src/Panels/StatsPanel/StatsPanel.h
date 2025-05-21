#pragma once

#include <SFML/System.hpp>

class StatsPanel
{
private:
    sf::Time accumulated_ = sf::Time::Zero;
    float fps_ = 0.0f;

    unsigned int totalParticles_ = 0;

public:
    StatsPanel();

    void update(sf::Time dt, int numParticles);

    void render();
};