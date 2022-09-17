#include "PhysicsComponent.h"
#include <cmath>

PhysicsComponent::PhysicsComponent(Entity& entity)
	: Component(entity)
{
}

void PhysicsComponent::update()
{
	position += velocity * dt;
	velocity = { 0, 0 };
}

sf::FloatRect PhysicsComponent::getBoundingBox()
{
	return sf::FloatRect(position, boxSizes);
}

sf::FloatRect PhysicsComponent::getMovedBoundingBox()
{
	return sf::FloatRect(position + velocity * dt, boxSizes);
}

void PhysicsComponent::resolveCollision(sf::FloatRect collision)
{
	float coeffx = 1;
	float coeffy = 1;
	auto [l, t, w, h] = collision;
	auto r = l + w;
	auto b = t + h;
	auto [dx, dy] = (velocity * dt);
	float x_top_bounds[] = {
		(r - position.x) / dx,
		(l - position.x - boxSizes.x) / dx,
	};

	float y_top_bounds[] = {
		(b - position.y) / dy,
		(t - position.y - boxSizes.y) / dy
	};

	for (auto val : x_top_bounds)
		if (val > 0)
			coeffx = std::min(coeffx, val - 0.001f);

	for (auto val : y_top_bounds)
		if (val > 0)
			coeffy = std::min(coeffy, val - 0.001f);
	velocity.x *= coeffx;
	velocity.y *= coeffy;
}
