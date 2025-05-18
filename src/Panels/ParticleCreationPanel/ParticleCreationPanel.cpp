#include "ParticleCreationPanel.h"

#include <imgui.h>

ParticleCreationPanel::ParticleCreationPanel()
{   
    particleMass_ = 100.0;
    particleRadius_ = 10.0;
}

double ParticleCreationPanel::getParticleMass()
{
    return particleMass_;
}

double ParticleCreationPanel::getParticleRadius()
{
    return particleRadius_;
}

sf::Color ParticleCreationPanel::getParticleColor()
{
    return color_;
}

void ParticleCreationPanel::update()
{   
    ImGui::SetNextWindowSize(ImVec2(300, 175), ImGuiCond_Once);
    ImGui::Begin("Particle Creation Panel");

    ImGui::Text("Particle Mass:");
    ImGui::InputDouble("##ParticleMass", &particleMass_);

    ImGui::Text("Particle Radius:");
    ImGui::InputDouble("##ParticleRadius", &particleRadius_);

    ImGui::Text("Particle Color:");
    static float color[] = {1.f, 0.f, 0.f};
    
    ImGui::ColorEdit3("##ColorEditor", color);

    color_.r = static_cast<sf::Uint8>(color[0] * 255.f);
    color_.g = static_cast<sf::Uint8>(color[1] * 255.f);
    color_.b = static_cast<sf::Uint8>(color[2] * 255.f);
    color_.a = 255;

    ImGui::End();
}