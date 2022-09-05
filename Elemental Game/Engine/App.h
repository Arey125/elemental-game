#pragma once
#include "Window.h"
#include "Updatable.h"
#include "Renderable.h"

class App :
	public Updatable,
	public Renderable
{
public:
	App(Window& window);
	void run();

private:

	void update();
	void render();

	Window& window;
};

