#pragma once
#include <string>

struct SpawnGroup
{
	const std::string name;
	const int spawnCap;
	const bool peaceful;
	const bool rare;
	const int immediateDespawnRange;

	static constexpr int despawnRangeStart = 32;

	SpawnGroup(std::string name, int spawnCap, bool peaceful, bool rare, int immediateDespawnRange);

	static const SpawnGroup MONSTER;
	static const SpawnGroup CREATURE;
	static const SpawnGroup AMBIENT;
	static const SpawnGroup AXOLOTLS;
	static const SpawnGroup UNDERGROUND_WATER_CREATURE;
	static const SpawnGroup WATER_CREATURE;
	static const SpawnGroup WATER_AMBIENT;
	static const SpawnGroup MISC;
};
