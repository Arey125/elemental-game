#include "GameLayer.h"

GameLayer::GameLayer(LayerStack& layer_stack)
	: Layer(layerStack),
	rect({50, 50})
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
	float dx = 0, dy = 0;
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
		dx -= dt;
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
		dx += dt;
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
		dy -= dt;
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
		dy += dt;
	float speed = 200;
	rect.move({ speed * dx, speed * dy });
}

void GameLayer::render()
{
	renderTarget.draw(rect);
}
