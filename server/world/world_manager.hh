#pragma once
#include "world.hh"
#include "server/utils/logger/logger.hh"

#include <vector>
#include <string>

class WorldManager
{
	Logger logger{ "WorldManager" };
	std::vector<World> worlds;

public:
	void tick();

	World* getWorld(const std::string& name);

	void loadAll();
	bool load(const std::string& name);
	void loadOrCreate(const std::string& name, WorldType* type);

	void saveAll();
	void save(const std::string& name);
	void save(const World& world);

	void create(const std::string& name, WorldType* type);
};
