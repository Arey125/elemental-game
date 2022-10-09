#pragma once
#include <Engine/Updatable.h>
#include <Engine/Renderable.h>

const int CHUNK_SIZE = 64;
const int TILE_SIZE = 4;
const int RENDERED_TILE_SIZE = TILE_SIZE;
const int PIXEL_SIZE = 2;
const int CHUNK_SIDE = CHUNK_SIZE * TILE_SIZE * PIXEL_SIZE;


class Chunk:
	public Updatable,
	public Renderable
{
public:
	Chunk(int minX, int minY);

	void update() override;
	void render() override;

	//Collision detection
	bool intersects(sf::FloatRect boundingBox);
	std::vector<sf::FloatRect> checkCollision(sf::FloatRect boundingBox);

private:
	char tileTypes[CHUNK_SIZE * CHUNK_SIZE];
	int minX, minY;
	sf::Texture tileset;
	sf::VertexArray vertexArray;	
};
