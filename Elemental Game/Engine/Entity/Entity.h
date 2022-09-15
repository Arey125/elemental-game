#pragma once
#include "Engine/Updatable.h"
#include "Engine/Renderable.h"
#include "Components.h"

class Entity:
	public Updatable,
	public Renderable
{
public:
	Entity();
	~Entity();

	virtual void update();
	virtual void render();

	AnimationComponent* getAnimationComponent() { return animationComponent; }
	PhysicsComponent* getPhysicsComponent() { return physicsComponent; }
	ControllerComponent* getControllerComponent() { return controllerComponent; }

protected:
	AnimationComponent *animationComponent;
	PhysicsComponent *physicsComponent;
	ControllerComponent *controllerComponent;
};

