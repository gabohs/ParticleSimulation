#pragma once

#include "../../Simulation/SimulationParams.h"

class SimulationControlPanel
{
private:
    SimulationParams params_;

public:
    SimulationControlPanel();

    const SimulationParams& getParams() const; // to pass the parameters defined by the user to the Solver

    void render();
};