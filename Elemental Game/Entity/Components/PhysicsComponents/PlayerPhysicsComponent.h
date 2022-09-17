#pragma once
#include "Engine/Entity.h"

class PlayerPhysicsComponent :
	public PhysicsComponent
{
public:
	PlayerPhysicsComponent(Entity& entity);

	virtual void update();

	virtual void onCollision(sf::FloatRect collision);
};