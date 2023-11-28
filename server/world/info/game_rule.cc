#include "game_rule.hh"

#include <utility>
#include <vector>

std::vector<GameRule*> gameRules;

GameRule::GameRule(int id, std::string name, const std::variant<bool, int>& value) :
		id(id), name(std::move(name)), value(value)
{
	gameRules.push_back(this);
}

GameRule::GameRule(int id, std::string name, const std::variant<bool, int>& value, const std::function<void(GameRule*)>& onUpdate) :
		GameRule(id, std::move(name), value)
{
	this->onUpdate = onUpdate;
	gameRules.push_back(this);
}


bool GameRule::operator==(const GameRule& rhs) const
{
	return id == rhs.id;
}

bool GameRule::operator!=(const GameRule& rhs) const
{
	return !(rhs == *this);
}

std::vector<GameRule> GameRule::copyValues()
{
	std::vector<GameRule> rules;
	for (GameRule* rule : gameRules)
		rules.push_back(*rule);
	return rules;
}

const GameRule GameRule::DO_FIRE_TICK = {0, "doFireTick", true};
const GameRule GameRule::MOB_GRIEFING = {1, "mobGriefing", true};
const GameRule GameRule::KEEP_INVENTORY = {2, "keepInventory", false};
const GameRule GameRule::DO_MOB_SPAWNING = {3, "doMobSpawning", true};
const GameRule GameRule::DO_MOB_LOOT = {4, "doMobLoot", true};
const GameRule GameRule::DO_TILE_DROPS = { 5, "doTileDrops", true};
const GameRule GameRule::DO_ENTITY_DROPS = {6, "doEntityDrops", true};
const GameRule GameRule::COMMAND_BLOCK_OUTPUT = {7, "commandBlockOutput", true};
const GameRule GameRule::NATURAL_REGENERATION = {8, "naturalRegeneration", true};
const GameRule GameRule::DO_DAYLIGHT_CYCLE = {9, "doDaylightCycle", true};
const GameRule GameRule::LOG_ADMIN_CMMANDS = {10, "logAdminCommands", true};
const GameRule GameRule::SHOW_DEATH_MESSAGES = {11, "showDeathMessages", true};
const GameRule GameRule::RANDOM_TICK_SPEED = {12, "randomTickSpeed", 3};
const GameRule GameRule::SEND_COMMAND_FEEDBACK = {13, "sendCommandFeedback", true};
const GameRule GameRule::REDUCED_DEBUG_INFO = {14, "reducedDebugInfo", false, [](GameRule* rule){}};
const GameRule GameRule::SPECTATORS_GENERATE_CHUNKS = {15, "spectatorsGenerateChunks", true};
const GameRule GameRule::SPAWN_RADIUS = {16, "spawnRadius", 10};
const GameRule GameRule::DISABLE_ELYTRA_MOVEMENT_CHECK = {17, "disableElytraMovementCheck", false};
const GameRule GameRule::MAX_ENTITY_CRAMMING = {18, "maxEntityCramming", 24};
const GameRule GameRule::DO_WEATHER_CYCLE = {19, "doWeatherCycle", true};
const GameRule GameRule::DO_LIMITED_CRAFTING = {20, "doLimitedCrafting", false, [](GameRule* rule){}};
const GameRule GameRule::MAX_COMMAND_CHAIN_LENGTH = {21, "maxCommandChainLength", 65536};
const GameRule GameRule::COMMAND_MODIFICATION_BLOCK_LIMIT = {22, "commandModificationBlockLimit", 32768};
const GameRule GameRule::ANNOUNCE_ADVANCEMENTS = {23, "announceAdvancements", true};
const GameRule GameRule::DISABLE_RAIDS = {24, "disableRaids", false};
const GameRule GameRule::DO_INSOMNIA = {25, "doInsomnia", true};
const GameRule GameRule::DO_IMMEDIATE_RESPAWN = {26, "doImmediateRespawn", false, [](GameRule* rule){}};
const GameRule GameRule::DROWNING_DAMAGE = {27, "drowningDamage", true};
const GameRule GameRule::FALL_DAMAGE = {28, "fallDamage", true};
const GameRule GameRule::FIRE_DAMAGE = {29, "fireDamage", true};
const GameRule GameRule::FREEZE_DAMAGE = {30, "freezeDamage", true};
const GameRule GameRule::DO_PATROL_SPAWNING = {31, "doPatrolSpawning", true};
const GameRule GameRule::DO_TRADER_SPAWNING = {32, "doTraderSpawning", true};
const GameRule GameRule::DO_WARDEN_SPAWNING = {33, "doWardenSpawning", true};
const GameRule GameRule::FORGIVE_DEAD_PLAYERS = {34, "forgiveDeadPlayers", true};
const GameRule GameRule::UNIVERSAL_ANGER = {35, "universalAnger", false};
const GameRule GameRule::PLAYERS_SLEEPING_PERCENTAGE = {36, "playersSleepingPercentage", 100};
const GameRule GameRule::BLOCK_EXPLOSION_DROP_DECAY = {37, "blockExplosionDropDecay", true};
const GameRule GameRule::MOB_EXPLOSION_DROP_DECAY = {38, "mobExplosionDropDecay", true};
const GameRule GameRule::TNT_EXPLOSION_DROP_DECAY = {39, "tntExplosionDropDecay", false};
const GameRule GameRule::SNOW_ACCUMULATION_HEIGHT = {40, "snowAccumulationHeight", 1};
const GameRule GameRule::WATER_SOURCE_CONVERSION = {41, "waterSourceConversion", true};
const GameRule GameRule::LAVA_SOURCE_CONVERSION = {42, "lavaSourceConversion", false};
const GameRule GameRule::GLOBAL_SOUND_EVENTS = {43, "globalSoundEvents", true};
const GameRule GameRule::DO_VINES_SPREAD = {44, "doVinesSpread", true};
const GameRule GameRule::ENDER_PEARLS_VANISH_ON_DEATH = {45, "enderPearlsVanishOnDeath", true};
