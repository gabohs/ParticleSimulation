#pragma once

#include <SFML/Graphics.hpp>

class ConfigPanel
{
private:
    bool shouldRender_ = false;

    float panelTransparency_ = 1.0f;
    sf::Color winBgColor_;

    void renderCustomCloseButton();

    void panelConfigTab();
    void windowConfigTab();

public:
    ConfigPanel();

    sf::Color getWinBgColor();

    void shouldRender();

    void render();
};