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
