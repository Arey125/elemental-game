#include "PlayerAnimationComponent.h"

PlayerAnimationComponent::PlayerAnimationComponent(Entity& entity)
	: AnimationComponent(entity), state(0)
{
}

void PlayerAnimationComponent::render()
{
	sf::RectangleShape rect({ 16, 16 });
	auto position = entity.getPhysicsComponent()->getPosition();
	rect.setPosition(position);
	if (state)
		rect.setFillColor(sf::Color::Red);

	renderTarget.draw(rect);
	setState(0);
}

void PlayerAnimationComponent::setState(int state)
{
	this->state = state;
}
