#include <utility>

#include "world.hh"

World::World(std::string name, const WorldType& type) : name(std::move(name)), type(type)
{
}

void World::tick()
{

}

Chunk* World::getChunkAt(int x, int z)
{
	for (Chunk& chunk : chunks)
		if (chunk.getX() == x && chunk.getZ() == z)
			return &chunk;

	return nullptr;
}
