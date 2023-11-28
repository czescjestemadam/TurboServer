#pragma once
#include "punishment_type.hh"
#include "server/auth/game_profile.hh"

#include <chrono>

class Punishment
{
public:
	using tpoint = std::chrono::time_point<std::chrono::system_clock>;
	using tduration = std::chrono::system_clock::duration;

	long id = -1;

	GameProfile profile;
	uint ip;

	PunishmentType* type;
	std::string reason;

	tpoint start;
	tpoint end;
	bool revoked = false;


	Punishment() = default;
	Punishment(long id, const GameProfile& profile, uint ip, PunishmentType* type, const std::string& reason, const tpoint& start, const tpoint& end, bool revoked);

	bool isExpired() const;
	tduration untilExpires() const;

	bool operator==(const Punishment& rhs) const;
	bool operator!=(const Punishment& rhs) const;
};
