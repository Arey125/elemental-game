#include <cassert>
#include "Chunk.h"

Chunk::Chunk(int chunkX, int chunkY)
	: minX(chunkX * CHUNK_SIDE), minY(chunkY * CHUNK_SIDE),
	vertexArray(sf::Quads, 4 * CHUNK_SIZE * CHUNK_SIZE)
{
	std::fill(std::begin(tileTypes), std::end(tileTypes), 0);

	if (chunkX || chunkY)
		for (int i = 0; i < CHUNK_SIZE; i++)
		{
			int x = rand() % CHUNK_SIZE;
			int y = rand() % CHUNK_SIZE;
			tileTypes[x + CHUNK_SIZE * y] = 1;
		}
	assert(tileset.loadFromFile("./asserts/Tiles.png"));

	for (int i = 0; i < CHUNK_SIZE; i++)
		for (int j = 0; j < CHUNK_SIZE; j++)
		{

			float xWorld = minX / PIXEL_SIZE + i * RENDERED_TILE_SIZE;
			float yWorld = minY / PIXEL_SIZE + j * RENDERED_TILE_SIZE;


			float x = xWorld;
			float y = yWorld;

			float type = tileTypes[i + j * CHUNK_SIZE];

			sf::Vertex* vertexes = &vertexArray[4 * (i + CHUNK_SIZE * j)];

			vertexes[0].position = { x, y};
			vertexes[1].position = { x + RENDERED_TILE_SIZE, y };
			vertexes[2].position = { x + RENDERED_TILE_SIZE, y + RENDERED_TILE_SIZE };
			vertexes[3].position = { x, y + RENDERED_TILE_SIZE };

			vertexes[0].texCoords =	  { type * TILE_SIZE, 0 };
			vertexes[1].texCoords = { type * TILE_SIZE, TILE_SIZE };
			vertexes[2].texCoords = { type * TILE_SIZE + TILE_SIZE, TILE_SIZE };
			vertexes[3].texCoords = { type * TILE_SIZE + TILE_SIZE, 0 };
		}
}

void Chunk::update()
{
}

void Chunk::render()
{
	sf::RenderStates renderStates(&tileset);
	renderStates.transform.scale(2.f, 2.f);
	renderTarget.draw(vertexArray, renderStates);
}

bool Chunk::intersects(sf::FloatRect boundingBox)
{
	sf::FloatRect chunkBoundingBox(minX, minY, CHUNK_SIDE, CHUNK_SIDE);
	return boundingBox.intersects(chunkBoundingBox);
}

std::vector<sf::FloatRect> Chunk::checkCollision(sf::FloatRect boundingBox)
{
	auto chunkCoordBoundingBox(boundingBox);
	
	auto [left, top, width, height] = chunkCoordBoundingBox;
	
	left -= minX;
	top -= minY;

	left /= PIXEL_SIZE * TILE_SIZE;
	top /= PIXEL_SIZE * TILE_SIZE;
	width /= PIXEL_SIZE * TILE_SIZE;
	height /= PIXEL_SIZE * TILE_SIZE;

	std::vector<sf::FloatRect> result;

	for (int i = std::max((int)floor(left), 0); i <= std::min((int)floor(left + width), CHUNK_SIZE - 1);i++)
		for (int j = std::max((int)floor(top), 0); j <= std::min((int)floor(top + height), CHUNK_SIZE - 1); j++) {
			if (tileTypes[i + j * CHUNK_SIZE])
				result.emplace_back(minX + i * PIXEL_SIZE * TILE_SIZE,
						minY + j * PIXEL_SIZE * TILE_SIZE,
						PIXEL_SIZE * TILE_SIZE,
						PIXEL_SIZE * TILE_SIZE );
	}

	return result;
}