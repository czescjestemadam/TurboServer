#pragma once
#include "server/auth/game_profile.hh"

#include <string>
#include <optional>
#include <unordered_map>
#include <chrono>
#include <future>

class MojangAPI
{
	static std::unordered_map<std::string, std::pair<UUID, std::chrono::system_clock::time_point>> nameToUuidCache;
	static std::unordered_map<UUID, std::pair<GameProfile, std::chrono::system_clock::time_point>> uuidToProfileCache;

public:
	static std::optional<UUID> getUUID(const std::string& name);
	static std::future<std::optional<UUID>> asyncGetUUID(const std::string& name);

	static std::optional<GameProfile> getProfile(const UUID& uuid);
	static std::future<std::optional<GameProfile>> asyncGetProfile(const UUID& uuid);
};
