#include "SimulationControlPanel.h"

#include <imgui.h>

SimulationControlPanel::SimulationControlPanel()
{
    params_.gravity = 9.8;
}

const SimulationParams &SimulationControlPanel::getParams() const
{
    return params_;
}

void SimulationControlPanel::update()
{
    ImGui::SetNextWindowSize(ImVec2(300, 120), ImGuiCond_Once);
    ImGui::Begin("Simulation Control Panel");

    ImGui::Text("Gravity: ");
    ImGui::SliderFloat("##gravityslider", &params_.gravity, 0.0f, 100.0f);

    ImGui::Text("Restitution: ");
    ImGui::SliderFloat("##restitution", &params_.restitution, 0.0f, 1.0f);

    ImGui::End();
}