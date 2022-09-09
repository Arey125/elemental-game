#pragma once
#include "Engine/Layer.h"

class MainMenuLayer:
	public Layer
{
public:
	MainMenuLayer(LayerStack& layer_stack);

	virtual void onEvent(sf::Event event);
	virtual bool blockLower();

	virtual void update();
	virtual void render();

private:
	sf::Color bgColor;
};

