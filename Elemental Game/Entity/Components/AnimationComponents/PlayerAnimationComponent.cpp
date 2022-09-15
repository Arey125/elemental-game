#include "PlayerAnimationComponent.h"

PlayerAnimationComponent::PlayerAnimationComponent(Entity& entity)
	: AnimationComponent(entity)
{
}

void PlayerAnimationComponent::render()
{
	sf::RectangleShape rect({ 50, 50 });
	auto position = entity.getPhysicsComponent()->getPosition();
	rect.setPosition(position);

	renderTarget.draw(rect);
}
