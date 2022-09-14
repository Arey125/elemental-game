#pragma once
#include "Engine/Updatable.h"
#include "Engine/Entity/Components/Component.h"

class PhysicsComponent :
	public Updatable,
	public Component
{
public:
	PhysicsComponent(Entity& entity);

	virtual void update();

	sf::Vector2f getPosition() { return position; }
	void move(sf::Vector2f velocity) { position += velocity * dt; }
protected:
	sf::Vector2f position;
};