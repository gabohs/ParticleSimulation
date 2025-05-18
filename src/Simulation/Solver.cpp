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

void Solver::update(sf::Time dt, sf::Vector2u winSize)
{
    for (auto& particle : particles_)
    {
        const float pxPerM = 2.0f;

        sf::Vector2f vel = particle.getVel();
        sf::Vector2f pos = particle.getPos();

        vel.y += params_.gravity * dt.asSeconds() * pxPerM;
        particle.setVel(vel);

        pos += vel * dt.asSeconds();
        particle.setPos(pos);

        particle.collideWithWall(winSize);
    }
}

const std::vector<Particle>& Solver::getParticles()
{
    return particles_;
}