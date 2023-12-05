#include "punishment_type.hh"

#include <utility>
#include <vector>

std::vector<PunishmentType*> types;

PunishmentType::PunishmentType(int id, std::string name, bool canJoin, bool canChat) : id(id), name(std::move(name)), join(canJoin), chat(canChat)
{
	types.push_back(this);
}


int PunishmentType::getId() const
{
	return id;
}

const std::string& PunishmentType::getName() const
{
	return name;
}

bool PunishmentType::canJoin() const
{
	return join;
}

bool PunishmentType::canChat() const
{
	return chat;
}


bool PunishmentType::operator==(const PunishmentType& rhs) const
{
	return id == rhs.id;
}

bool PunishmentType::operator!=(const PunishmentType& rhs) const
{
	return !(rhs == *this);
}


PunishmentType* PunishmentType::fromId(int id)
{
	for (PunishmentType* type : types)
		if (type->id == id)
			return type;

	return nullptr;
}

PunishmentType* PunishmentType::fromName(const std::string& name)
{
	for (PunishmentType* type : types)
		if (type->name == name)
			return type;

	return nullptr;
}

PunishmentType PunishmentType::WARN = { 0, "warn", true, true };
PunishmentType PunishmentType::KICK = { 1, "kick", true, true };
PunishmentType PunishmentType::MUTE = { 2, "mute", true, false };
PunishmentType PunishmentType::BAN = { 3, "ban", false, true };
