#include "GameLayer.h"
#include "Entity/Player.h"

GameLayer::GameLayer(LayerStack& layer_stack)
	: Layer(layerStack), player(new Player()),
	rect({ 50, 50 })
{
	rect.setPosition({ 300, 300 });
}

GameLayer::~GameLayer()
{
	delete player;
}

void GameLayer::onEvent(sf::Event event)
{
}

bool GameLayer::blockLower()
{
	return true;
}

void GameLayer::update()
{
	player->getControllerComponent()->update();
	auto box = player->getPhysicsComponent()->getMovedBoundingBox();
	if (box.intersects(rect.getGlobalBounds()))
		player->getPhysicsComponent()->onCollision(rect.getGlobalBounds());
	auto result = tilemap.checkCollision(box);
	for (auto collision : result)
		player->getPhysicsComponent()->onCollision(collision);
	player->getPhysicsComponent()->update();
}

void GameLayer::render()
{
	auto playerPhysicsComponent = player->getPhysicsComponent();
	auto player_position = playerPhysicsComponent->getPosition();
	auto player_box_sizes = sf::Vector2f{
		playerPhysicsComponent->getBoundingBox().width,
		playerPhysicsComponent->getBoundingBox().height
	};

	auto player_center = player_position + player_box_sizes * 0.5f;
	auto render_tartget_size = sf::Vector2f(renderTarget.getSize());
	
	sf::View player_view(player_center, render_tartget_size);
	renderTarget.setView(player_view);
	
	tilemap.render();
	renderTarget.draw(rect);
	player->render();
}
