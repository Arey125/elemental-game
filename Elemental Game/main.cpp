#include <iostream>
#include <SFML/Graphics.hpp>
#include "Engine/App.h"

int main()
{
	Window window;
	App app(window);
	app.run();
}