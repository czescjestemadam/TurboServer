#pragma once
#include "punishment.hh"

class PunishmentBuilder
{
	Punishment p;

public:
	explicit PunishmentBuilder(const GameProfile& profile);
	explicit PunishmentBuilder(uint ip);

	PunishmentBuilder& type(PunishmentType* type);
	PunishmentBuilder& reason(const std::string& reason);

	PunishmentBuilder& start(const Punishment::tpoint& start);
	PunishmentBuilder& end(const Punishment::tpoint& end);
	PunishmentBuilder& duration(const Punishment::tduration& duration);

	Punishment build();
};
