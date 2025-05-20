#include "App.h"

#include <imgui.h>
#include <imgui-SFML.h>

#include "../Theme/style.h"
#include "../Theme/Font/JETBRAINSMONONL-BOLD.h"

#include "Simulation/Particle.h"

App::App()
{
    sf::Vector2u resolution = {sf::VideoMode::getDesktopMode().width, sf::VideoMode::getDesktopMode().height};

    window_.create(sf::VideoMode(resolution.x,resolution.y), "Particle Simulator", sf::Style::Default);

    ImGui::SFML::Init(window_);

    // load custom font
    ImGuiIO& io = ImGui::GetIO();

    ImFontConfig font_cfg;
    font_cfg.FontDataOwnedByAtlas = false;

    io.Fonts->AddFontFromMemoryTTF(JetBrainsMonoNL, FontSize, 15.0f, &font_cfg);

    ImGui::SFML::UpdateFontTexture();
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

        float particleMass = particleCreationPanel.getParticleMass();
        float particleRadius = particleCreationPanel.getParticleRadius();
        sf::Color particleColor = particleCreationPanel.getParticleColor();

        Particle p(mousePos, particleMass, particleRadius, particleColor);
        
        // prevent overlap when creating particles
        bool overlaps = false;
        for (const auto& particle : solver_.getParticles())
        {
            float dist = std::sqrt( (particle.getPos().x - mousePos.x) * (particle.getPos().x - mousePos.x) + 
                                    (particle.getPos().y - mousePos.y) * (particle.getPos().y - mousePos.y) );  
            
            if (dist < p.getRadius() + particleRadius) 
            {
                overlaps = true;
                break;
            }
        }
        if (!overlaps)
        {
            solver_.addParticle(p);
        }
            
    }
    mouseLeftWasPressed_ = mouseCurrentlyPressed;

    solver_.setSimulationParams(simControlPanel.getParams());
    solver_.update(dt, {window_.getSize().x, window_.getSize().y});
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