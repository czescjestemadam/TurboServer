#pragma once
#include <string>
#include <variant>
#include <functional>

class GameRule
{
	int id;

public:
	std::string name;
	std::variant<bool, int> value;
	std::function<void(GameRule*)> onUpdate;


	GameRule(int id, std::string name, const std::variant<bool, int>& value);
	GameRule(int id, std::string name, const std::variant<bool, int>& value, const std::function<void(GameRule*)>& onUpdate);

	template<class T>
	T get() const
	{
		return std::get<T>(value);
	}

	template<class T>
	void set(const T& val)
	{
		value = val;
		onUpdate(this);
	}

	bool operator==(const GameRule& rhs) const;
	bool operator!=(const GameRule& rhs) const;

	static std::vector<GameRule> copyValues();

	static const GameRule DO_FIRE_TICK;
	static const GameRule MOB_GRIEFING;
	static const GameRule KEEP_INVENTORY;
	static const GameRule DO_MOB_SPAWNING;
	static const GameRule DO_MOB_LOOT;
	static const GameRule DO_TILE_DROPS;
	static const GameRule DO_ENTITY_DROPS;
	static const GameRule COMMAND_BLOCK_OUTPUT;
	static const GameRule NATURAL_REGENERATION;
	static const GameRule DO_DAYLIGHT_CYCLE;
	static const GameRule LOG_ADMIN_CMMANDS;
	static const GameRule SHOW_DEATH_MESSAGES;
	static const GameRule RANDOM_TICK_SPEED;
	static const GameRule SEND_COMMAND_FEEDBACK;
	static const GameRule REDUCED_DEBUG_INFO;
	static const GameRule SPECTATORS_GENERATE_CHUNKS;
	static const GameRule SPAWN_RADIUS;
	static const GameRule DISABLE_ELYTRA_MOVEMENT_CHECK;
	static const GameRule MAX_ENTITY_CRAMMING;
	static const GameRule DO_WEATHER_CYCLE;
	static const GameRule DO_LIMITED_CRAFTING;
	static const GameRule MAX_COMMAND_CHAIN_LENGTH;
	static const GameRule COMMAND_MODIFICATION_BLOCK_LIMIT;
	static const GameRule ANNOUNCE_ADVANCEMENTS;
	static const GameRule DISABLE_RAIDS;
	static const GameRule DO_INSOMNIA;
	static const GameRule DO_IMMEDIATE_RESPAWN;
	static const GameRule DROWNING_DAMAGE;
	static const GameRule FALL_DAMAGE;
	static const GameRule FIRE_DAMAGE;
	static const GameRule FREEZE_DAMAGE;
	static const GameRule DO_PATROL_SPAWNING;
	static const GameRule DO_TRADER_SPAWNING;
	static const GameRule DO_WARDEN_SPAWNING;
	static const GameRule FORGIVE_DEAD_PLAYERS;
	static const GameRule UNIVERSAL_ANGER;
	static const GameRule PLAYERS_SLEEPING_PERCENTAGE;
	static const GameRule BLOCK_EXPLOSION_DROP_DECAY;
	static const GameRule MOB_EXPLOSION_DROP_DECAY;
	static const GameRule TNT_EXPLOSION_DROP_DECAY;
	static const GameRule SNOW_ACCUMULATION_HEIGHT;
	static const GameRule WATER_SOURCE_CONVERSION;
	static const GameRule LAVA_SOURCE_CONVERSION;
	static const GameRule GLOBAL_SOUND_EVENTS;
	static const GameRule DO_VINES_SPREAD;
	static const GameRule ENDER_PEARLS_VANISH_ON_DEATH;
};
