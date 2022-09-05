#include "Window.h"

sf::RenderWindow* Window::renderWindow = nullptr;

Window::Window()
{
	renderWindow = new sf::RenderWindow(sf::VideoMode(800, 600), "My window");
}

bool Window::isOpen()
{
	return renderWindow->isOpen();
}

bool Window::pollEvent(sf::Event& e)
{
	bool result = renderWindow->pollEvent(e);
	if (e.type == sf::Event::Closed)
		renderWindow->close();
	return result;
}

void Window::display()
{
	renderWindow->display();
}
