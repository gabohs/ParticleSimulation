#include "App.h"

#include <imgui.h>
#include <imgui-SFML.h>

#include "../Theme/style.h"
#include "../Theme/Font/JETBRAINSMONONL-BOLD.h"

#include "Simulation/Particle.h"

App::App()
{
    sf::Vector2f resolution = {
        static_cast<float>(sf::VideoMode::getDesktopMode().width),
        static_cast<float>(sf::VideoMode::getDesktopMode().height)
    };

    window_.create(
        sf::VideoMode(
            static_cast<unsigned int>(resolution.x),
            static_cast<unsigned int>(resolution.y)
        ),
        "Particle Simulator",
        sf::Style::Default
    );

    ImGui::SFML::Init(window_);

    // load custom font
    ImGuiIO& io = ImGui::GetIO();

    ImFontConfig font_cfg;
    font_cfg.FontDataOwnedByAtlas = false;

    io.Fonts->AddFontFromMemoryTTF(JetBrainsMonoNL, FontSize, 15.0f, &font_cfg);

    ImGui::SFML::UpdateFontTexture();

    // // Initialize particle simulation with references to panel variables
}

void App::handleEvents()
{
    sf::Event event;
    while (window_.pollEvent(event)) 
    {
        ImGui::SFML::ProcessEvent(window_, event);
        if (event.type == sf::Event::Closed) 
        {
            window_.close();
        }
    }
}

void App::update(sf::Time dt)
{
    ImGui::SFML::Update(window_, dt);

    particleCreationPanel.update();
    simControlPanel.update();

    bool mouseCurrentlyPressed = sf::Mouse::isButtonPressed(sf::Mouse::Left);
    bool aKeyIsHeld = sf::Keyboard::isKeyPressed(sf::Keyboard::A);

    if (mouseCurrentlyPressed && !mouseLeftWasPressed_ && aKeyIsHeld)
    {
        sf::Vector2f mousePos = window_.mapPixelToCoords(sf::Mouse::getPosition(window_));

        double particleMass = particleCreationPanel.getParticleMass();
        double particleRadius = particleCreationPanel.getParticleRadius();
        sf::Color particleColor = particleCreationPanel.getParticleColor();

        Particle p(mousePos, particleMass, particleRadius, particleColor);
        solver_.addParticle(p);

    }
    mouseLeftWasPressed_ = mouseCurrentlyPressed;

    solver_.setSimulationParams(simControlPanel.getParams());
    solver_.update(dt);
}

void App::render()
{
    window_.clear();

    setStyle::GruvBox_Dark();

    solver_.drawParticles(window_);

    ImGui::SFML::Render(window_);

    window_.display();
}

void App::run()
{
    while (window_.isOpen()) 
    {
        handleEvents();
        update(clock_.restart());
        render();
    }
    ImGui::SFML::Shutdown();
}