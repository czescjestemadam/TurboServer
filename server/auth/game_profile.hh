#pragma once
#include "server/utils/uuid.hh"

#include <string>

class GameProfile
{
public:
	std::string name;
	UUID uuid;

	std::string textures;

	GameProfile() = default;
	GameProfile(const std::string& name, const UUID& uuid);

	static GameProfile fromName(const std::string& name);
	static GameProfile fromUUID(const UUID& uuid);
};
