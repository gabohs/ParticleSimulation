#include "Solver.h"

void Solver::collideWithWall(Particle& particle, sf::Vector2u winSize)
{
    sf::Vector2f windowSize(static_cast<float>(winSize.x), static_cast<float>(winSize.y));

    sf::Vector2f pos = particle.getPos();
    sf::Vector2f vel = particle.getVel();
    float radius = particle.getRadius();

    // Left and Right
    if (pos.x < 0.0f)
    {   
        pos.x = 0.0f;
        vel.x *= -params_.restitution;
    }
    else if ( (pos.x + radius) > windowSize.x )
    {   
        pos.x = windowSize.x - radius;   
        vel.x *= -params_.restitution;
    }

    // Top and Bottom
    if (pos.y < 0.0f)
    {   
        pos.y = 0.0f;
        vel.y *= -params_.restitution;
    }
    else if ( (pos.y + radius) > windowSize.y )
    {   
        pos.y = windowSize.y - radius;
        vel.y *= -params_.restitution;
    }

    particle.setPos(pos);
    particle.setVel(vel);
}

bool Solver::areColliding(Particle &a, Particle &b)
{
    sf::Vector2f distance = a.getPos() - b.getPos();
    
    float radii_sum = a.getRadius() + b.getRadius();

    if ( (distance.x * distance.x) + (distance.y * distance.y) <= (radii_sum * radii_sum) )
    {
        return true;
    }
    return false;
}

void Solver::setSimulationParams(const SimulationParams &params)
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

void Solver::handleCollision()
{
    for (size_t i = 0; i < particles_.size(); i++)
    {   
        for (size_t j = i + 1;  j < particles_.size(); j++)
        {   
            Particle& p1 = particles_[i];
            Particle& p2 = particles_[j];

            if (areColliding(p1, p2))
            {
                float restitution = params_.restitution;
                float m1 = p1.getMass();
                float m2 = p2.getMass();

                sf::Vector2f velDiff = math::vecSubtract(p1.getVel(), p2.getVel());   // v1 - v2
                sf::Vector2f posDiff = math::vecSubtract(p1.getPos(), p2.getPos());   // r1 - r2

                sf::Vector2f projection = math::vecProjection(velDiff, math::vecNormalize(posDiff));

                // Calculate mass ratios for each ball
                float mRatio1 = (1 + restitution) * m2 / (m1 + m2);
                float mRatio2 = (1 + restitution) * m1 / (m1 + m2);

                // Update velocities 
                sf::Vector2f newVel1 = math::vecSubtract(p1.getVel(), math::vecMultiply(projection, mRatio1));
                sf::Vector2f newVel2 = math::vecAdd(p2.getVel(), math::vecMultiply(projection, mRatio2));  // note addition here

                p1.setVel(newVel1);
                p2.setVel(newVel2);
            }
        }
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

        collideWithWall(particle, winSize);
    }
    handleCollision();
    
}

const std::vector<Particle>& Solver::getParticles()
{
    return particles_;
}