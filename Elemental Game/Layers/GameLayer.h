#pragma once
#include <Engine/Layer.h>
#include <Engine/Entity.h>
#include <Engine/TileMap/Tilemap.h>

class GameLayer :
    public Layer
{
public:
	GameLayer(LayerStack& layer_stack);
	~GameLayer();

	virtual void onEvent(sf::Event event);
	virtual bool blockLower();

	virtual void update();
	virtual void render();

private:
	Entity* player;
	sf::RectangleShape rect;
	Tilemap tilemap;
};

