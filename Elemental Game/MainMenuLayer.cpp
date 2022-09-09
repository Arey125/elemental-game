#include "MainMenuLayer.h"

MainMenuLayer::MainMenuLayer(LayerStack& layer_stack)
	: Layer(layer_stack), bgColor(sf::Color::Black)
{

}

void MainMenuLayer::onEvent(sf::Event event)
{
	if (event.type == sf::Event::MouseButtonPressed)
		bgColor = sf::Color::Red;
}

bool MainMenuLayer::blockLower()
{
	return false;
}

void MainMenuLayer::update()
{
}

void MainMenuLayer::render()
{
	renderTarget.clear(bgColor);
}
