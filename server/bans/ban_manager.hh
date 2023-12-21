#pragma once
#include "punishment.hh"
#include "server/auth/game_profile.hh"

#include <vector>

class BanManager
{
	std::vector<Punishment> punishments;

	// perms
	std::vector<GameProfile> bannedPlayers;
	std::vector<uint> bannedIps;

public:
	void load();
	void save();

	bool hasActivePunishment(const GameProfile& profile, PunishmentType* type);
	std::vector<Punishment> getActivePunishments(const GameProfile& profile, PunishmentType* type);

	void punish(const Punishment& punishment);

	void revoke(const Punishment& punishment);
	void revoke(const GameProfile& profile, PunishmentType* type);
};
