#include <SFML/Window.hpp>

#include "ControllerComponent.h"
#include "Engine/Entity.h"

ControllerComponent::ControllerComponent(Entity& entity)
	: Component(entity)
{
}

void ControllerComponent::update()
{
	float dx = 0, dy = 0;
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
		dx--;
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
		dx++;
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
		dy--;
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
		dy++;
	float speed = 200;
	dx *= speed;
	dy *= speed;
	entity.getPhysicsComponent()->move({ dx, dy });
}
