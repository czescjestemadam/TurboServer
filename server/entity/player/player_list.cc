#include "player_list.hh"

void PlayerList::tick()
{
	for (const std::unique_ptr<PlayerEntity>& p : players)
		p->tick();
}


std::vector<PlayerEntity*> PlayerList::getPlayers() const
{
	std::vector<PlayerEntity*> ret;
	for (const std::unique_ptr<PlayerEntity>& p : players)
		ret.push_back(p.get());
	return ret;
}

std::vector<PlayerEntity*> PlayerList::getPlayers(World* world) const
{
	std::vector<PlayerEntity*> ret;
	for (const std::unique_ptr<PlayerEntity>& p : players)
		if (p->world == world)
			ret.push_back(p.get());
	return ret;
}


PlayerEntity* PlayerList::getPlayer(const std::string& name) const
{
	for (const std::unique_ptr<PlayerEntity>& p : players)
		if (p->name == name)
			return p.get();
	return nullptr;
}

PlayerEntity* PlayerList::getPlayer(const UUID& id) const
{
	for (const std::unique_ptr<PlayerEntity>& p : players)
		if (p->uuid == id)
			return p.get();
	return nullptr;
}


void PlayerList::addPlayer(std::unique_ptr<PlayerEntity>&& player)
{
	players.push_back(std::move(player));
}
