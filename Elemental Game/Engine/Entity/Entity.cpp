#include "Entity.h"

Entity::Entity():
	animationComponent(nullptr),
	physicsComponent(nullptr),
	controllerComponent(nullptr)
{

}

Entity::~Entity()
{
	if (animationComponent)
		delete animationComponent;
	if (physicsComponent)
		delete physicsComponent;
	if (controllerComponent)
		delete controllerComponent;
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
