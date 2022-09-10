#include <ImGUI/imgui.h>
#include <ImGUI/imgui-sfml.h>

#include "MainMenuLayer.h"
#include "GameLayer.h"

MainMenuLayer::MainMenuLayer(LayerStack& layer_stack)
	: Layer(layer_stack), bgColor(sf::Color::Black)
{

}

void MainMenuLayer::onEvent(sf::Event event)
{

}

bool MainMenuLayer::blockLower()
{
	return false;
}

void MainMenuLayer::update()
{
    ImGui::Begin("Elemental game");

    if (ImGui::Button("Start game")) {
		appendLayer<GameLayer>();
		remove();
    }
	if (ImGui::Button("Exit")) {
		remove();
	}
    ImGui::End();
}

void MainMenuLayer::render()
{
	renderTarget.clear(bgColor);
}
