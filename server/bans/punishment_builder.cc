#include "punishment_builder.hh"

PunishmentBuilder::PunishmentBuilder(const GameProfile& profile)
{
	p.profile = profile;
}

PunishmentBuilder::PunishmentBuilder(uint ip)
{
	p.ip = ip;
}


PunishmentBuilder& PunishmentBuilder::type(PunishmentType* type)
{
	p.type = type;
	return *this;
}

PunishmentBuilder& PunishmentBuilder::reason(const std::string& reason)
{
	p.reason = reason;
	return *this;
}


PunishmentBuilder& PunishmentBuilder::start(const Punishment::tpoint& start)
{
	p.start = start;
	return *this;
}

PunishmentBuilder& PunishmentBuilder::end(const Punishment::tpoint& end)
{
	p.end = end;
	return *this;
}

PunishmentBuilder& PunishmentBuilder::duration(const Punishment::tduration& duration)
{
	p.start = std::chrono::system_clock::now();
	p.end = p.start + duration;
	return *this;
}


Punishment PunishmentBuilder::build()
{
	return p;
}
