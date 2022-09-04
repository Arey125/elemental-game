#include "App.h"

App::App()
	: window(sf::VideoMode(800, 600), "My window")
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
        if (event.type == sf::Event::Closed)
            window.close();
    }
}

void App::render()
{
    sf::CircleShape shape(100, 100);
    shape.setPosition(200, 200);

    window.clear();
    window.draw(shape);
    window.display();
}
