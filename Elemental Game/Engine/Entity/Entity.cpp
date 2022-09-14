#include "Entity.h"

Entity::Entity():
	animationComponent(new AnimationComponent(*this)),
	physicsComponent(new PhysicsComponent(*this)),
	controllerComponent(new ControllerComponent(*this))
{
}

void Entity::update()
{
	controllerComponent->update();
	physicsComponent->update();
	animationComponent->update();
}

void Entity::render()
{
	animationComponent->render();
}
