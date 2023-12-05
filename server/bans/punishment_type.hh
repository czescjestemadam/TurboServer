#pragma once
#include <string>

class PunishmentType
{
	int id;
	std::string name;
	bool join;
	bool chat;

public:
	PunishmentType(int id, std::string  name, bool canJoin, bool canChat);

	int getId() const;
	const std::string& getName() const;
	bool canJoin() const;
	bool canChat() const;

	bool operator==(const PunishmentType& rhs) const;
	bool operator!=(const PunishmentType& rhs) const;

	static PunishmentType* fromId(int id);
	static PunishmentType* fromName(const std::string& name);

	static PunishmentType WARN;
	static PunishmentType KICK;
	static PunishmentType MUTE;
	static PunishmentType BAN;
};
