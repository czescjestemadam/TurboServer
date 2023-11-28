#include <utility>

#include "spawn_group.hh"


SpawnGroup::SpawnGroup(std::string name, int spawnCap, bool peaceful, bool rare, int immediateDespawnRange)
		: name(std::move(name)), spawnCap(spawnCap), peaceful(peaceful), rare(rare), immediateDespawnRange(immediateDespawnRange)
{
}

const SpawnGroup SpawnGroup::MONSTER = { "monster", 70, false, false, 128 };
const SpawnGroup SpawnGroup::CREATURE = { "creature", 10, true, true, 128 };
const SpawnGroup SpawnGroup::AMBIENT = { "ambient", 15, true, false, 128 };
const SpawnGroup SpawnGroup::AXOLOTLS = { "axolotls", 5, true, false, 128 };
const SpawnGroup SpawnGroup::UNDERGROUND_WATER_CREATURE = { "underground_water_creature", 5, true, false, 128 };
const SpawnGroup SpawnGroup::WATER_CREATURE = { "water_creature", 5, true, false, 128 };
const SpawnGroup SpawnGroup::WATER_AMBIENT = { "water_ambient", 20, true, false, 64 };
const SpawnGroup SpawnGroup::MISC = { "misc", -1, true, true, 128 };
