#pragma once
#include "server/entity/living_entity.hh"
#include "server/network/socket/player_socket.hh"
#include "game_mode.hh"
#include "server/inventory/player_inventory.hh"
#include "server/inventory/ender_chest_container.hh"
#include "server/auth/game_profile.hh"

#include <optional>

class PlayerEntity : public LivingEntity
{
public:
	PlayerSocket* socket = nullptr;

	GameProfile profile;
	std::string name;
	std::string displayname;
	GameMode* gameMode = &GameMode::SURVIVAL;
	GameMode* previousGameMode = &GameMode::UNDEFINED;

	PlayerInventory inventory;
	EnderChestContainer enderChest;
	// food

	int sleepCounter;
	bool wasUnderwater;
	PlayerAbilities abilities;

	struct Experience
	{
		int level;
		int total;
		float progress;
	} exp;

	// ItemStack lastItemInMainHand;
	// ItemCooldowns itemCooldowns;

	std::optional<Vec3d> lastDeathLocation;
	std::optional<Vec3d> respawnLocation;
	// fishing hook

	Entity* camera;


	explicit PlayerEntity(PlayerSocket* socket);

	void setGameMode(GameMode* mode);


	std::string toString() const;
};
