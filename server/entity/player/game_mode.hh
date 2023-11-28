#pragma once
#include "player_abilities.hh"

#include <string>

class GameMode
{
	int id;
	std::string name;

public:
	GameMode(int id, std::string name);

	int getId() const;
	const std::string& getName() const;

	void updateAbilities(PlayerAbilities& abilities) const;
	bool isBlockPlacingRestricted() const;

	bool operator==(const GameMode& rhs) const;
	bool operator!=(const GameMode& rhs) const;

	static GameMode* fromId(int id);
	static GameMode* fromName(const std::string& name);

	static GameMode UNDEFINED;
	static GameMode SURVIVAL;
	static GameMode CREATIVE;
	static GameMode ADVENTURE;
	static GameMode SPECTATOR;
};
