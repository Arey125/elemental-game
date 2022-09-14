#pragma once
#include "Engine/Updatable.h"
#include "Engine/Entity/Components/Component.h"

class ControllerComponent :
	public Updatable,
	public Component
{
public:
	ControllerComponent(Entity& entity);

	virtual void update();
};