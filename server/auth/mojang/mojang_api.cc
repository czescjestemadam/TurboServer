#include "mojang_api.hh"

// GET
static constexpr const char* NAME_TO_UUID = "https://api.mojang.com/users/profiles/minecraft/{}";
static constexpr const char* UUID_TO_PROFILE = "https://sessionserver.mojang.com/session/minecraft/profile/{}";

// POST
static constexpr const char* PLAYER_CERTIFICATES = "https://api.minecraftservices.com/player/certificates"; // bearer

// GET
static constexpr const char* NAME_CHANGE_INFO = "https://api.minecraftservices.com/minecraft/profile/namechange"; // bearer


std::optional<UUID> MojangAPI::getUUID(const std::string& name)
{
	return {};// todo
}

std::future<std::optional<UUID>> MojangAPI::asyncGetUUID(const std::string& name)
{
	return std::async(std::launch::async, &MojangAPI::getUUID, name);
}

std::optional<GameProfile> MojangAPI::getProfile(const UUID& uuid)
{
	return {};// todo
}

std::future<std::optional<GameProfile>> MojangAPI::asyncGetProfile(const UUID& uuid)
{
	return std::async(std::launch::async, &MojangAPI::getProfile, uuid);
}
