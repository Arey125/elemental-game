#pragma once
#include <Engine/Layer.h>

class GameLayer :
    public Layer
{
public:
	GameLayer(LayerStack& layer_stack);

	virtual void onEvent(sf::Event event);
	virtual bool blockLower();

	virtual void update();
	virtual void render();

private:
	sf::RectangleShape rect;
};

