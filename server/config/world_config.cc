#include "world_config.hh"

#include "json_helper.hh"

void WorldConfig::load(nlohmann::json&& j)
{
	JSON_HELPER_READ(generateStructures)
	JSON_HELPER_READ(allowNether)
	JSON_HELPER_READ(allowEnd)

	JSON_HELPER_READ(syncChunkWrites)
	JSON_HELPER_READ(chunkGcTicks)
	JSON_HELPER_READ(chunkUnloadDelayTicks)
	JSON_HELPER_READ(preventMovingIntoUnloadedChunks)
	JSON_HELPER_READ(maxAutoSaveChunksPerTick)

	JSON_HELPER_READ(spawnNpcs)
	JSON_HELPER_READ(spawnAnimals)
	JSON_HELPER_READ(spawnMonsters)
	JSON_HELPER_READ(ticksPerAnimalSpawn)
	JSON_HELPER_READ(ticksPerMonsterSpawn)
	JSON_HELPER_READ(ticksPerAutosave)

	JSON_HELPER_READ(spawnProtection)
	JSON_HELPER_READ(spawnKeepLoaded)
	JSON_HELPER_READ(spawnChunkLoadedRadius)

	JSON_HELPER_READ(levelType)
	JSON_HELPER_READ(levelSeed)
	JSON_HELPER_READ(maxWorldSize)
	JSON_HELPER_READ(worldsDir)

	JSON_HELPER_READ(mergeRadiusExp)
	JSON_HELPER_READ(mergeRadiusItem)

	JSON_HELPER_READ(itemDespawnRateTicks)
	JSON_HELPER_READ(mobSpawnRange)

	JSON_HELPER_READ(growthModifierCactus)
	JSON_HELPER_READ(growthModifierMelon)
	JSON_HELPER_READ(growthModifierPumpkin)
	JSON_HELPER_READ(growthModifierSapling)
	JSON_HELPER_READ(growthModifierCane)
	JSON_HELPER_READ(growthModifierMushroom)
	JSON_HELPER_READ(growthModifierWheat)

	JSON_HELPER_READ(entityActivationRangeAnimals)
	JSON_HELPER_READ(entityActivationRangeMonsters)
	JSON_HELPER_READ(entityActivationRangeMisc)

	JSON_HELPER_READ(tickInactiveVillagers)

	JSON_HELPER_READ(entityTrackingRangeDisplay)
	JSON_HELPER_READ(entityTrackingRangePlayers)
	JSON_HELPER_READ(entityTrackingRangeAnimals)
	JSON_HELPER_READ(entityTrackingRangeMonsters)
	JSON_HELPER_READ(entityTrackingRangeMisc)
	JSON_HELPER_READ(entityTrackingRangeOther)

	JSON_HELPER_READ(disableSpawnerMobsAI)

	JSON_HELPER_READ(zombieAggressiveToVillagers)

	JSON_HELPER_READ(maxEntityCollisions)
	JSON_HELPER_READ(onlyPlayersCollide)
	JSON_HELPER_READ(allowVehicleCollisions)

	JSON_HELPER_READ(dragonDeathSoundRadius)
	JSON_HELPER_READ(witherSpawnSoundRadius)

	JSON_HELPER_READ(maxTickTimeTile)
	JSON_HELPER_READ(maxTickTimeEntity)

	JSON_HELPER_READ(hopperAmount)
	JSON_HELPER_READ(hopperTransferTicks)
	JSON_HELPER_READ(hopperCheckTicks)

	JSON_HELPER_READ(hungerJumpWalkExhaustion)
	JSON_HELPER_READ(hungerJumpSprintExhaustion)
	JSON_HELPER_READ(hungerCombatExhaustion)
	JSON_HELPER_READ(hungerRegenExhaustion)
	JSON_HELPER_READ(hungerSwimMultiplier)
	JSON_HELPER_READ(hungerSprintMultiplier)
	JSON_HELPER_READ(hungerOtherMultiplier)
}

nlohmann::json WorldConfig::save()
{
	nlohmann::json j;

	JSON_HELPER_WRITE(generateStructures)
	JSON_HELPER_WRITE(allowNether)
	JSON_HELPER_WRITE(allowEnd)

	JSON_HELPER_WRITE(syncChunkWrites)
	JSON_HELPER_WRITE(chunkGcTicks)
	JSON_HELPER_WRITE(chunkUnloadDelayTicks)
	JSON_HELPER_WRITE(preventMovingIntoUnloadedChunks)
	JSON_HELPER_WRITE(maxAutoSaveChunksPerTick)

	JSON_HELPER_WRITE(spawnNpcs)
	JSON_HELPER_WRITE(spawnAnimals)
	JSON_HELPER_WRITE(spawnMonsters)
	JSON_HELPER_WRITE(ticksPerAnimalSpawn)
	JSON_HELPER_WRITE(ticksPerMonsterSpawn)
	JSON_HELPER_WRITE(ticksPerAutosave)

	JSON_HELPER_WRITE(spawnProtection)
	JSON_HELPER_WRITE(spawnKeepLoaded)
	JSON_HELPER_WRITE(spawnChunkLoadedRadius)

	JSON_HELPER_WRITE(levelType)
	JSON_HELPER_WRITE(levelSeed)
	JSON_HELPER_WRITE(maxWorldSize)
	JSON_HELPER_WRITE(worldsDir)

	JSON_HELPER_WRITE(mergeRadiusExp)
	JSON_HELPER_WRITE(mergeRadiusItem)

	JSON_HELPER_WRITE(itemDespawnRateTicks)
	JSON_HELPER_WRITE(mobSpawnRange)

	JSON_HELPER_WRITE(itemDespawnRateTicks)
	JSON_HELPER_WRITE(mobSpawnRange)

	JSON_HELPER_WRITE(growthModifierCactus)
	JSON_HELPER_WRITE(growthModifierMelon)
	JSON_HELPER_WRITE(growthModifierPumpkin)
	JSON_HELPER_WRITE(growthModifierSapling)
	JSON_HELPER_WRITE(growthModifierCane)
	JSON_HELPER_WRITE(growthModifierMushroom)
	JSON_HELPER_WRITE(growthModifierWheat)

	JSON_HELPER_WRITE(entityActivationRangeAnimals)
	JSON_HELPER_WRITE(entityActivationRangeMonsters)
	JSON_HELPER_WRITE(entityActivationRangeMisc)

	JSON_HELPER_WRITE(tickInactiveVillagers)

	JSON_HELPER_WRITE(entityTrackingRangeDisplay)
	JSON_HELPER_WRITE(entityTrackingRangePlayers)
	JSON_HELPER_WRITE(entityTrackingRangeAnimals)
	JSON_HELPER_WRITE(entityTrackingRangeMonsters)
	JSON_HELPER_WRITE(entityTrackingRangeMisc)
	JSON_HELPER_WRITE(entityTrackingRangeOther)

	JSON_HELPER_WRITE(disableSpawnerMobsAI)

	JSON_HELPER_WRITE(zombieAggressiveToVillagers)

	JSON_HELPER_WRITE(maxEntityCollisions)
	JSON_HELPER_WRITE(onlyPlayersCollide)
	JSON_HELPER_WRITE(allowVehicleCollisions)

	JSON_HELPER_WRITE(dragonDeathSoundRadius)
	JSON_HELPER_WRITE(witherSpawnSoundRadius)

	JSON_HELPER_WRITE(maxTickTimeTile)
	JSON_HELPER_WRITE(maxTickTimeEntity)

	JSON_HELPER_WRITE(hopperAmount)
	JSON_HELPER_WRITE(hopperTransferTicks)
	JSON_HELPER_WRITE(hopperCheckTicks)

	JSON_HELPER_WRITE(hungerJumpWalkExhaustion)
	JSON_HELPER_WRITE(hungerJumpSprintExhaustion)
	JSON_HELPER_WRITE(hungerCombatExhaustion)
	JSON_HELPER_WRITE(hungerRegenExhaustion)
	JSON_HELPER_WRITE(hungerSwimMultiplier)
	JSON_HELPER_WRITE(hungerSprintMultiplier)
	JSON_HELPER_WRITE(hungerOtherMultiplier)

	return j;
}

std::string WorldConfig::getName()
{
	return "world";
}
