#include "PlayerPhysicsComponent.h"

PlayerPhysicsComponent::PlayerPhysicsComponent(Entity& entity)
	: PhysicsComponent(entity)
{
	position = { 100, 100 };
	boxSizes = { 16, 16 };
	velocity = { 0, 0 };
}

void PlayerPhysicsComponent::update()
{
	PhysicsComponent::update();
}

void PlayerPhysicsComponent::onCollision(sf::FloatRect collision)
{
	resolveCollision(collision);
	entity.getAnimationComponent()->setState(1);
}
