#include "game_mode.hh"

#include <utility>
#include <vector>

static std::vector<GameMode*> modes;

GameMode::GameMode(int id, std::string name) : id(id), name(std::move(name))
{
	modes.push_back(this);
}

int GameMode::getId() const
{
	return id;
}

const std::string& GameMode::getName() const
{
	return name;
}

void GameMode::updateAbilities(PlayerAbilities& abilities) const
{
	if (*this == CREATIVE)
	{
		abilities.mayFly = true;
		abilities.instabuild = true;
		abilities.invulnerable = true;
	}
	else if (*this == SPECTATOR)
	{
		abilities.mayFly = true;
		abilities.instabuild = false;
		abilities.invulnerable = true;
		abilities.flying = true;
	}
	else
	{
		abilities.mayFly = false;
		abilities.instabuild = false;
		abilities.invulnerable = false;
		abilities.flying = false;
	}

	abilities.mayBuild = !this->isBlockPlacingRestricted();
}

bool GameMode::isBlockPlacingRestricted() const
{
	return *this == ADVENTURE || *this == SPECTATOR;
}


bool GameMode::operator==(const GameMode& rhs) const
{
	return id == rhs.id;
}

bool GameMode::operator!=(const GameMode& rhs) const
{
	return !(rhs == *this);
}


GameMode* GameMode::fromId(int id)
{
	for (GameMode* mode: modes)
		if (mode->id == id)
			return mode;

	return nullptr;
}

GameMode* GameMode::fromName(const std::string& name)
{
	for (GameMode* mode: modes)
		if (mode->name == name)
			return mode;

	return nullptr;
}

GameMode GameMode::UNDEFINED = { -1, "undefined" };
GameMode GameMode::SURVIVAL = { 0, "survival" };
GameMode GameMode::CREATIVE = { 1, "creative" };
GameMode GameMode::ADVENTURE = { 2, "adventure" };
GameMode GameMode::SPECTATOR = { 3, "spectator" };
