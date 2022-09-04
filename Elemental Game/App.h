#pragma once
#include "Window.h"
#include "Updatable.h"

class App : public Updatable
{
public:
	App();
	void run();

private:

	void update();
	void render();

	Window window;
};

