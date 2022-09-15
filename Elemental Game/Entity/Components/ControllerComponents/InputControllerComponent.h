#pragma once
#include <Engine/Entity.h>

class InputControllerComponent :
	public ControllerComponent
{
public:
	InputControllerComponent(Entity& entity);

	virtual void update() override;
};