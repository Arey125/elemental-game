#pragma once
#include <Engine/Updatable.h>
#include <Engine/Renderable.h>

#include "Chunk.h"


class Tilemap:
	public Updatable,
	public Renderable
{
public:
	Tilemap();

	void update() override {}
	void render() override;
	std::vector<sf::FloatRect> checkCollision(sf::FloatRect boundingBox);

private:
	std::vector<Chunk> chunks;
};
