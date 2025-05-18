#include "Solver.h"

void Solver::setSimulationParams(const SimulationParams& params)
{
    params_ = params; 
}

void Solver::addParticle(const Particle& particle)
{
    particles_.push_back(particle);
}

void Solver::drawParticles(sf::RenderWindow &window)
{
    for (auto& particle : particles_)
    {
        window.draw(particle.getShape());
    }
}

void Solver::update(sf::Time dt)
{
    for (auto& particle : particles_)
    {
        const double pxPerM = 2;

        particle.setVel().y += params_.gravity * dt.asSeconds() * pxPerM;   
    
        particle.setPos() += particle.getVel() * dt.asSeconds();

        particle.getShape().setPosition(particle.getPos());
    }
}

const std::vector<Particle>& Solver::getParticles()
{
    return particles_;
}