#pragma once
#include "Engine/Renderable.h"
#include "Engine/Updatable.h"
#include "LayerStack.h"

class Layer:
	public Renderable,
	public Updatable
{
public:
	Layer(LayerStack& layer_stack);

	virtual void onEvent(sf::Event event) = 0;
	virtual bool blockLower() = 0;

protected:
	template<class LayerType>
	void appendLayer()
	{
		layerStack.pushLayer(new LayerType(layerStack));
	}

	void remove();

	LayerStack& layerStack;
};

