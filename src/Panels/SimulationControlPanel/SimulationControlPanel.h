#pragma once

#include "../../Simulation/SimulationParams.h"

class SimulationControlPanel
{
private:
    SimulationParams params_;

public:
    SimulationControlPanel();

    const SimulationParams& getParams() const;

    void update();
};