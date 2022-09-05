#pragma once

#include <SFML/Graphics.hpp>

class Window
{

public:
	Window();

	bool isOpen();
	bool pollEvent(sf::Event& e);

	void display();

	friend class Renderable;

private:
	static sf::RenderWindow* renderWindow;
};

