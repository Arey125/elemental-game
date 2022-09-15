#include "GameLayer.h"
#include "Entity/Player.h"

GameLayer::GameLayer(LayerStack& layer_stack)
	: Layer(layerStack), entity(new Player())
{
}

GameLayer::~GameLayer()
{
	delete entity;
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
	entity->update();
}

void GameLayer::render()
{
	entity->render();
}
