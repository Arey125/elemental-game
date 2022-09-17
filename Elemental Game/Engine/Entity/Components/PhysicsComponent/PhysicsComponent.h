#pragma once
#include "Engine/Updatable.h"
#include "Engine/Entity/Components/Component.h"
#include <SFML/Graphics.hpp>

class PhysicsComponent :
	public Updatable,
	public Component
{
public:
	PhysicsComponent(Entity& entity);

	virtual void update();

	// Getters
	sf::Vector2f getPosition() { return position; }
	sf::Vector2f getVelocity() { return velocity; }
	sf::FloatRect getBoundingBox();
	sf::FloatRect getMovedBoundingBox();

	// Events
	virtual void onCollision(sf::FloatRect collision) {};

	void move(sf::Vector2f velocity) { this->velocity += velocity; }
	void resolveCollision(sf::FloatRect collision);

protected:

	sf::Vector2f position;
	sf::Vector2f velocity;
	sf::Vector2f boxSizes;
};