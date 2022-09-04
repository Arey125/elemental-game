#pragma once

#include <SFML/Graphics.hpp>

class Window
{

public:
	Window();

	bool isOpen();
	bool pollEvent(sf::Event& e);

	friend class App;
private:
	static sf::RenderWindow* renderWindow;
};

