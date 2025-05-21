#pragma once

// This struct represents the simulation physics parameters and is initialized and modified by the SimulationControlPanel and used by the solver.

struct SimulationParams 
{
    float gravity;
    float restitution;
};