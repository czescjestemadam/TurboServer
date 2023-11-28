#pragma once
#include "world.hh"

#include <vector>
#include <string>

class WorldManager
{
	std::vector<World> worlds;

public:
	void tick();

	void loadAll();
	void load(const std::string& name);

	void saveAll();
	void save(const std::string& name);

	void create(const std::string& name, WorldType type);

	std::vector<std::string> listWorlds() const;
};
