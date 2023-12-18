#pragma once
#include "player_entity.hh"

#include <vector>

class PlayerList
{
	std::vector<std::unique_ptr<PlayerEntity>> players;

public:
	void tick();

	std::vector<PlayerEntity*> getPlayers() const;
	std::vector<PlayerEntity*> getPlayers(World* world) const;

	PlayerEntity* getPlayer(const std::string& name) const;
	PlayerEntity* getPlayer(const UUID& id) const;

	void addPlayer(std::unique_ptr<PlayerEntity>&& player);

private:
	void scramble();
};
