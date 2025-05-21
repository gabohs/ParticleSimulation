#include "ConfigPanel.h"

#include <imgui.h>

#include "../../Theme/colors.h"

ConfigPanel::ConfigPanel()
{
}

void ConfigPanel::renderCustomCloseButton()
{   
    ImGui::BeginGroup();

    ImGui::Text("Configuration Panel");

    ImGui::SameLine(ImGui::GetWindowWidth() - 35); // Close button

    float radius = 7.0f;
    ImVec2 pos = ImGui::GetCursorScreenPos();
    ImVec2 center = ImVec2(pos.x + radius, pos.y + radius);

    ImGui::InvisibleButton("##close_button", ImVec2(radius * 2, radius * 2));

    ImDrawList* draw_list = ImGui::GetWindowDrawList();
    draw_list->AddCircleFilled(center, radius, ImGui::ColorConvertFloat4ToU32(Colors::Red));

    // close window if clicked
    if (ImGui::IsItemClicked()) 
    {
        shouldRender_ = false;
    }

    ImGui::EndGroup();
}

void ConfigPanel::panelConfigTab()
{
    // Panel Transparency
    ImGuiStyle& style = ImGui::GetStyle();

    ImGui::Text("Panel Transparency");
    ImGui::SliderFloat("##transparency", &panelTransparency_, 0.1f, 1.0f);

    style.Alpha = panelTransparency_;
}

void ConfigPanel::windowConfigTab()
{
    // Window Background color:
    ImGui::Text("Window Background Color:");
    static float color[] = {0.0f, 0.0f, 0.0f};

    ImGui::ColorEdit3("##windBgColorPicker", color);

    winBgColor_.r = static_cast<sf::Uint8>(color[0] * 255.f);
    winBgColor_.g = static_cast<sf::Uint8>(color[1] * 255.f);
    winBgColor_.b = static_cast<sf::Uint8>(color[2] * 255.f);
    winBgColor_.a = 255;
}

sf::Color ConfigPanel::getWinBgColor()
{
    return winBgColor_;
}

void ConfigPanel::shouldRender()
{
    shouldRender_ = true;
}

void ConfigPanel::render()
{
    if (shouldRender_)
    {
        ImGui::SetNextWindowSize(ImVec2(300, 300), ImGuiCond_Once);
        ImGui::Begin("Configuration Panel", nullptr, ImGuiWindowFlags_NoTitleBar);

        renderCustomCloseButton();

        ImGui::Separator();

        if (ImGui::BeginTabBar("Tabs"))
        {   
            if (ImGui::BeginTabItem("Panels"))
            {
                panelConfigTab();
                ImGui::EndTabItem();
            }

            if (ImGui::BeginTabItem("Window"))
            {
                windowConfigTab();
                ImGui::EndTabItem();
            }

            ImGui::EndTabBar();
            
        }

        ImGui::End();
    }
    
}