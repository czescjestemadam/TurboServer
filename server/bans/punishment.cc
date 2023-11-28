#include "punishment.hh"

#include <chrono>

Punishment::Punishment(long id, const GameProfile& profile, uint ip, PunishmentType* type, const std::string& reason, const tpoint& start, const tpoint& end, bool revoked) :
		id(id), profile(profile), ip(ip), type(type), reason(reason), start(start), end(end), revoked(revoked)
{
}

bool Punishment::isExpired() const
{
	return revoked || end < std::chrono::system_clock::now();
}

Punishment::tduration Punishment::untilExpires() const
{
	return end - std::chrono::system_clock::now();
}

bool Punishment::operator==(const Punishment& rhs) const
{
	return id == rhs.id;
}

bool Punishment::operator!=(const Punishment& rhs) const
{
	return !(rhs == *this);
}
