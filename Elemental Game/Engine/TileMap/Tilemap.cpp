#include "Tilemap.h"

Tilemap::Tilemap()
{
	for (int i = -5;i <= 5;i++)
		for (int j = -5; j <= 5; j++)
			chunks.emplace_back(i, j);
}

void Tilemap::render()
{
	for (auto chunk : chunks)
	{
		auto &view = renderTarget.getView();
		sf::FloatRect rect(
			view.getCenter() - view.getSize() * 0.5f,
			view.getSize()
		);
		if (!chunk.intersects(rect))
			continue;
		chunk.render();
	}
}

std::vector<sf::FloatRect> Tilemap::checkCollision(sf::FloatRect boundingBox)
{
	std::vector<sf::FloatRect> result;
	for (auto chunk : chunks) {
		if (!chunk.intersects(boundingBox))
			continue;
		
		auto chunk_result = chunk.checkCollision(boundingBox);
		std::copy(
			chunk_result.begin(),
			chunk_result.end(),
			std::back_inserter(result)
		);
	}
	return result;
}
