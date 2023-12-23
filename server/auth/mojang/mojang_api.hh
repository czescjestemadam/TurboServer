#pragma once
#include "server/auth/game_profile.hh"

#include <string>
#include <optional>
#include <future>

class MojangAPI
{
public:
	static std::optional<UUID> getUUID(const std::string& name);
	static std::future<std::optional<UUID>> asyncGetUUID(const std::string& name);

	static std::optional<GameProfile> getProfile(const UUID& uuid);
	static std::future<std::optional<GameProfile>> asyncGetProfile(const UUID& uuid);
};
