#include "LayerStack.h"
#include "Layer.h"

LayerStack::LayerStack()
{

}

void LayerStack::pushLayer(Layer* layer)
{
	pushQueue.push_back(layer);
}

void LayerStack::removeLayer(Layer* layer)
{
	removeQueue.push_back(layer);
}

void LayerStack::update()
{
	for (auto layer : removeQueue)
	{
		auto position = std::find(layers.begin(), layers.end(), layer);
		if (position == layers.end())
			return;
		delete (*position);
		layers.erase(position);
	}
	for (auto layer : pushQueue)
		layers.push_back(layer);

	pushQueue.clear();
	removeQueue.clear();

	for (auto it = layers.rbegin(); it != layers.rend(); it++)
	{
		auto& layer = **it;
		layer.update();
		if (layer.blockLower())
			break;
	}

}

void LayerStack::render()
{
	for (auto layer : layers)
		layer->render();
}

void LayerStack::onEvent(sf::Event event)
{
	for (auto it = layers.rbegin(); it != layers.rend(); it++)
	{
		auto& layer = **it;
		layer.onEvent(event);
		if (layer.blockLower())
			break;
	}
}
