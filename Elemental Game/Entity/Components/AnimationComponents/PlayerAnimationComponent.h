#pragma once
#include <Engine/Entity.h>

class PlayerAnimationComponent : public AnimationComponent
{
public:
	PlayerAnimationComponent(Entity& entity);

	virtual void render();
	virtual void setState(int state) override;

private:
	int state;
};