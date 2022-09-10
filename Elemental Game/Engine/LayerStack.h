#pragma once
#include <vector>

#include "Updatable.h"
#include "Renderable.h"

class Layer;

class LayerStack:
	public Updatable,
	public Renderable
{
public:
	LayerStack();

	void pushLayer(Layer *layer);
	void removeLayer(Layer* layer);

	virtual void update();
	virtual void render();

	void onEvent(sf::Event event);

private:
	std::vector<Layer*> layers;
	std::vector<Layer*> pushQueue;
	std::vector<Layer*> removeQueue;
};

