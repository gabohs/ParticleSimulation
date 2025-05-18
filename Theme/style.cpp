#include "style.h"

namespace setStyle
{
    void GruvBox_Dark()
    {
        ImGuiStyle& style = ImGui::GetStyle();

        style.WindowRounding = 10.f;
        style.FrameRounding  = 4.f;
        style.GrabRounding   = 10.f;
        style.PopupRounding  = 4.f;
        

        style.Colors[ImGuiCol_WindowBg]        = Colors::winBg;
        style.Colors[ImGuiCol_Text]            = Colors::Orange;

        style.Colors[ImGuiCol_Button]          = Colors::LightBlue;
        style.Colors[ImGuiCol_ButtonHovered]   = Colors::DarkBlue;

        style.Colors[ImGuiCol_FrameBg]         = Colors::Gray;
        style.Colors[ImGuiCol_InputTextCursor] = Colors::Orange;

        style.Colors[ImGuiCol_PopupBg]         = Colors::DarkGray;
        
    }
}

