#include "Player.h"
#include "Components.h"

Player::Player()
{
	controllerComponent = new InputControllerComponent(*this);
	animationComponent = new PlayerAnimationComponent(*this);
	physicsComponent = new PlayerPhysicsComponent(*this);
}
