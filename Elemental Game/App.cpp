#include "App.h"

App::App()
	: window()
{

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

    }
}

void App::render()
{
    sf::CircleShape shape(100, 100);
    shape.setPosition(200, 200);

    Window::renderWindow->clear();
    Window::renderWindow->draw(shape);
    Window::renderWindow->display();
}
