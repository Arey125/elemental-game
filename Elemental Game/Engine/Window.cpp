#include "Window.h"

sf::RenderWindow* Window::renderWindow = nullptr;

Window::Window() :
	m_renderWindow(sf::VideoMode(800, 600), "My window")
{
	renderWindow = &m_renderWindow;
}

bool Window::isOpen()
{
	return renderWindow->isOpen();
}

bool Window::pollEvent(sf::Event& e)
{
	if (!renderWindow->pollEvent(e))
		return false;
	if (e.type == sf::Event::Closed)
		renderWindow->close();
	return true;
}

void Window::display()
{
	renderWindow->display();
}
