#include "App.h"
#include "../MainMenuLayer.h"

App::App(Window& window)
    : window(window)
{
    layerStack.pushLayer(new MainMenuLayer(layerStack));
}

void App::run()
{
    while (window.isOpen())
    {
        update();
        render();
    }
}

void App::update()
{
    sf::Event event;
    while (window.pollEvent(event))
    {
        layerStack.onEvent(event);
    }
    layerStack.update();
}

void App::render()
{
    renderTarget.clear();
    layerStack.render();
    window.display();
}
