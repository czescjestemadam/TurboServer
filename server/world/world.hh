#pragma once
#include "server/world/info/world_type.hh"
#include "chunk.hh"
#include "server/world/info/difficulty.hh"
#include "server/world/info/game_rule_set.hh"
#include "server/utils/vec.hh"
#include "server/world/info/world_border.hh"

#include <string>
#include <vector>

class World
{
public:
	const std::string name;
	const WorldType type;

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

	std::vector<Chunk> chunks;


	World(std::string name, const WorldType& type);


	void tick();

	Chunk* getChunkAt(int x, int z);
};
