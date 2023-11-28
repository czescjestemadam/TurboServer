#pragma once
#include "iconfig.hh"

class WorldConfig : public IConfig
{
public:
	bool generateStructures = true;
	bool allowNether = true;
	bool allowEnd = true;

	bool syncChunkWrites = true;
	int chunkGcTicks = 0;
	int chunkUnloadDelayTicks = 200;
	bool preventMovingIntoUnloadedChunks = true;
	int maxAutoSaveChunksPerTick = 24;

	bool spawnNpcs = true;
	bool spawnAnimals = true;
	bool spawnMonsters = true;
	int ticksPerAnimalSpawn = 400;
	int ticksPerMonsterSpawn = 10;
	int ticksPerAutosave = 6000;

	int spawnProtection = 16;
	bool spawnKeepLoaded = false;
	int spawnChunkLoadedRadius = 10;

	// normal / flat
	std::string levelType = "normal";
	int levelSeed = -1;
	int maxWorldSize = 29999984;
	// worlds files location
	// "" = ./
	std::string worldsDir = "";

	float mergeRadiusExp = 3;
	float mergeRadiusItem = 2.5f;

	int itemDespawnRateTicks = 6000;
	int mobSpawnRange = 6;

	int growthModifierCactus = 100;
	int growthModifierMelon = 100;
	int growthModifierPumpkin = 100;
	int growthModifierSapling = 100;
	int growthModifierCane = 100;
	int growthModifierMushroom = 100;
	int growthModifierWheat = 100;

	int entityActivationRangeAnimals = 32;
	int entityActivationRangeMonsters = 32;
	int entityActivationRangeMisc = 16;

	bool tickInactiveVillagers = true;

	int entityTrackingRangeDisplay = 128;
	int entityTrackingRangePlayers = 48;
	int entityTrackingRangeAnimals = 48;
	int entityTrackingRangeMonsters = 48;
	int entityTrackingRangeMisc = 32;
	int entityTrackingRangeOther = 64;

	bool disableSpawnerMobsAI = false;

	bool zombieAggressiveToVillagers = true;

	int maxEntityCollisions = 8;
	bool onlyPlayersCollide = false;
	bool allowVehicleCollisions = true;

	int dragonDeathSoundRadius = 0;
	int witherSpawnSoundRadius = 0;

	int maxTickTimeTile = 50;
	int maxTickTimeEntity = 50;

	int hopperAmount = 1;
	int hopperTransferTicks = 8;
	int hopperCheckTicks = 1;

	float hungerJumpWalkExhaustion = 0.05;
	float hungerJumpSprintExhaustion = 0.2;
	float hungerCombatExhaustion = 0.1;
	float hungerRegenExhaustion = 6.0;
	float hungerSwimMultiplier = 0.01;
	float hungerSprintMultiplier = 0.1;
	float hungerOtherMultiplier = 0.0;


	void load(nlohmann::json&& j) override;
	nlohmann::json save() override;

	std::string getName() override;
};
