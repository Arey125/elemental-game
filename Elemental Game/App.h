#pragma once
#include <SFML/Graphics.hpp>

class App
{
public:
	App();
	void run();

private:

	void update();
	void render();

	sf::RenderWindow window;
};

