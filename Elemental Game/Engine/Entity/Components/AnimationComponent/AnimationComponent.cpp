#include "AnimationComponent.h"
#include "Engine/Entity.h"

AnimationComponent::AnimationComponent(Entity& entity)
	: Component(entity)
{
}

void AnimationComponent::render()
{
	sf::RectangleShape rect({ 50, 50 });
	auto position = entity.getPhysicsComponent()->getPosition();
	rect.setPosition(position);
	
	renderTarget.draw(rect);
}

void AnimationComponent::update()
{
}
