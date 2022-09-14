#pragma once
#include "Engine/Renderable.h"
#include "Engine/Updatable.h"
#include "Engine/Entity/Components/Component.h"

class AnimationComponent:
	public Renderable,
	public Updatable,
	public Component
{
public:
	AnimationComponent(Entity& entity);

	virtual void render();
	virtual void update();

};