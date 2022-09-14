#include "Layer.h"
#include "LayerStack.h"

Layer::Layer(LayerStack& layer_stack)
	: layerStack(layer_stack)
{

}

void Layer::remove()
{
	layerStack.removeLayer(this);
}
