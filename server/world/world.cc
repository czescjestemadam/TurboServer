#include "world.hh"

World::World(std::string name, WorldType* type, long seed) : name(std::move(name)), type(type), seed(seed), generator(WorldGenerator::forType(type, seed))
{
}

void World::tick()
{
	// todo split to nonadjacent chunk sets
	for (Chunk& chunk : chunks)
		chunk.tick();
}


Chunk* World::getChunk(int x, int z)
{
	for (Chunk& chunk : chunks)
		if (chunk.x == x && chunk.z == z)
			return &chunk;

	return nullptr;
}

Chunk* World::getChunkAt(int blockX, int blockZ)
{
	return getChunk(blockX / 16, blockZ / 16); // todo test
}

Chunk* World::getChunkAt(const Vec3i& blockPos)
{
	return getChunkAt(blockPos.x, blockPos.z);
}


void World::generateChunk(int x, int z)
{
	chunks.push_back(generator->getChunk(x, z));
}


std::vector<Entity*> World::getEntities() const
{
	std::vector<Entity*> ret;
	for (const std::unique_ptr<Entity>& e : entities)
		ret.push_back(e.get());
	return ret;
}

Entity* World::getEntity(int id) const
{
	for (const std::unique_ptr<Entity>& e : entities)
		if (e->id == id)
			return e.get();
	return nullptr;
}

Entity* World::getEntity(const UUID& uuid) const
{
	for (const std::unique_ptr<Entity>& e : entities)
		if (e->uuid == uuid)
			return e.get();
	return nullptr;
}

void World::addEntity(std::unique_ptr<Entity>&& entity)
{
	entities.push_back(std::move(entity));
}
