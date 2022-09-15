#pragma once
#include <Engine/Entity.h>

class PlayerAnimationComponent : public AnimationComponent
{
public:
	PlayerAnimationComponent(Entity& entity);

	virtual void render();
};