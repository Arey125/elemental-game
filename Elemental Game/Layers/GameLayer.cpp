#include "GameLayer.h"
#include "Entity/Player.h"

GameLayer::GameLayer(LayerStack& layer_stack)
	: Layer(layerStack), entity(new Player()),
	rect({ 50, 50 })
{
	rect.setPosition({ 300, 300 });
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
	entity->getControllerComponent()->update();
	auto box = entity->getPhysicsComponent()->getMovedBoundingBox();
	if (box.intersects(rect.getGlobalBounds()))
		entity->getPhysicsComponent()->onCollision(rect.getGlobalBounds());
	entity->getPhysicsComponent()->update();
}

void GameLayer::render()
{
	renderTarget.draw(rect);
	entity->render();
}
