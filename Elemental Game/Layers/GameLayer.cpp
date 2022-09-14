#include "GameLayer.h"

GameLayer::GameLayer(LayerStack& layer_stack)
	: Layer(layerStack)
{
}

void GameLayer::onEvent(sf::Event event)
{
}

bool GameLayer::blockLower()
{
	return true;
}

void GameLayer::update()
{
	entity.update();
}

void GameLayer::render()
{
	entity.render();
}
