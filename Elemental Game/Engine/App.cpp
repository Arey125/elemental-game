#include <ImGUI/imgui.h>
#include <ImGUI/imgui-sfml.h>

#include "App.h"
#include "Layers/MainMenuLayer.h"

App::App(Window& window)
    : window(window)
{
    layerStack.pushLayer(new MainMenuLayer(layerStack));
    ImGui::SFML::Init(*window.renderWindow);
}

App::~App()
{
    ImGui::SFML::Shutdown();
}

void App::run()
{
    while (window.isOpen())
    {
        update();
        render();
        DeltaTimeManager::instance().updateDeltaTime();
    }
}

void App::update()
{
    sf::Event event;
    while (window.pollEvent(event))
    {
        ImGui::SFML::ProcessEvent(event);
        layerStack.onEvent(event);
    }

    ImGui::SFML::Update(*window.renderWindow, dTime);

    layerStack.update();
}

void App::render()
{
    renderTarget.clear();
    layerStack.render();
    ImGui::SFML::Render(*window.renderWindow);
    window.display();
}
