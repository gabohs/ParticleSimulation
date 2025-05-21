#include "StatsPanel.h"

#include "../../Theme/colors.h"

#include <imgui.h>

StatsPanel::StatsPanel()
{

}

void StatsPanel::update(sf::Time dt, int numParticles)
{   

    // calculate FPS
    accumulated_ += dt;

    if (accumulated_ >= sf::seconds(0.5f)) // update every half a second
    {
        fps_ = 1.0f / dt.asSeconds();
        accumulated_ = sf::Time::Zero;
    }

    // Get number of particles
    totalParticles_ = numParticles;
}

void StatsPanel::render()
{
    ImGui::SetNextWindowSize(ImVec2(300, 100), ImGuiCond_Once);
    ImGui::Begin("Simulation Stats");

    ImGui::Text("FPS: ");
    ImGui::SameLine();
    ImGui::TextColored(Colors::BrightRed, "%.1f", fps_);

    ImGui::Text("Particles: ");
    ImGui::SameLine();
    ImGui::TextColored(Colors::BrightRed, "%d", totalParticles_);

    ImGui::End();
}