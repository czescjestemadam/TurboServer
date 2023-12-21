#pragma once
#include "server/world/info/world_type.hh"
#include "chunk.hh"
#include "server/world/info/difficulty.hh"
#include "server/world/info/game_rule_set.hh"
#include "server/utils/vec.hh"
#include "server/world/info/world_border.hh"
#include "server/entity/entity.hh"
#include "generators/world_generator.hh"

#include <string>
#include <vector>
#include <memory>

class World
{
public:
	const std::string name;
	const WorldType* type;

	Vec3i spawnPos;
	float spawnAngle;
	ulong gameTime;
	ulong dayTime;
	bool thundering;
	ulong thunderingTime;
	bool raining;
	ulong rainingTime;
	bool hardcore;
	GameRuleSet gameRules;
	Difficulty* difficulty;
	WorldBorder border;
	long seed;

	std::unique_ptr<WorldGenerator> generator;

	std::vector<Chunk> chunks;
	std::vector<std::unique_ptr<Entity>> entities;


	World(std::string name, WorldType* type, long seed);


	void tick();

	Chunk* getChunk(int x, int z);
	Chunk* getChunkAt(int blockX, int blockZ);
	Chunk* getChunkAt(const Vec3i& blockPos);

	void generateChunk(int x, int z);

	std::vector<Entity*> getEntities() const;
	Entity* getEntity(int id) const;
	Entity* getEntity(const UUID& uuid) const;
	void addEntity(std::unique_ptr<Entity>&& entity);
};
