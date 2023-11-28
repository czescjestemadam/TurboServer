#include "game_profile.hh"

GameProfile::GameProfile(const std::string& name, const UUID& uuid) : name(name), uuid(uuid)
{
}

GameProfile GameProfile::fromName(const std::string& name)
{
	return { name, UUID::nil() };
}

GameProfile GameProfile::fromUUID(const UUID& uuid)
{
	return { "", uuid };
}
