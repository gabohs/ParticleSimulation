#pragma once

#include <iostream>

#include <SFML/Graphics.hpp>

#include "Simulation/Particle.h"
#include "Simulation/Solver.h"

#include "Panels/ParticleCreationPanel/ParticleCreationPanel.h"
#include "Panels/SimulationControlPanel/SimulationControlPanel.h"

class App 
{
private:
    sf::RenderWindow window_;
    sf::Clock clock_;

    Solver solver_;

    SimulationControlPanel simControlPanel;
    ParticleCreationPanel particleCreationPanel;

    void handleEvents();
    void update(sf::Time dt);
    void render();

    bool mouseLeftWasPressed_ = false;

public:
    App();
    void run();
};