#include "world_manager.hh"
#include "server/turbo_server.hh"

#include <random>

void WorldManager::tick()
{
	// todo multithreading
	for (World& world : worlds)
		world.tick();
}

World* WorldManager::getWorld(const std::string& name)
{
	for (World& world : worlds)
		if (world.name == name)
			return &world;
	return nullptr;
}

void WorldManager::loadAll()
{
	const WorldConfig& cfg = TurboServer::get()->getConfigManager().getWorldConfig();

	loadOrCreate("world", &WorldType::OVERWORLD);
	if (cfg.allowNether)
		loadOrCreate("world_nether", &WorldType::NETHER);
	if (cfg.allowEnd)
		loadOrCreate("world_the_end", &WorldType::THE_END);

	// todo custom/extra worlds
}


/**
 * \return true if loaded successfully or already loaded
 */
bool WorldManager::load(const std::string& name)
{
	if (getWorld(name))
	{
		logger.warn("World {} is already loaded", name);
		return true;
	}

	return false;

	logger.info("Loading world {}", name);
	// todo

	return false;
}

void WorldManager::loadOrCreate(const std::string& name, WorldType* type)
{
	if (!load(name))
		create(name, type);
}

void WorldManager::saveAll()
{
	for (World& world : worlds)
		save(world);
}

void WorldManager::save(const std::string& name)
{
	World* world = getWorld(name);
	if (world)
		save(*world);
}

void WorldManager::save(const World& world)
{
	logger.info("Saving world {}", world.name);

	// todo
}

void WorldManager::create(const std::string& name, WorldType* type)
{
	static std::random_device rd;
	static std::mt19937_64 rng(rd());
	static std::uniform_int_distribution<long> dist(LONG_MIN, LONG_MAX);

	const long seed = dist(rng);
	logger.info("Creating world {}[{}] with seed: {}", name, type->name, seed);

	World world(name, type, seed);

	// todo pregenerate x chunks

	worlds.push_back(std::move(world));
}
