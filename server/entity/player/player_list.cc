#include "player_list.hh"
#include "server/turbo_server.hh"

#include <random>

void PlayerList::tick()
{
	for (const std::unique_ptr<PlayerEntity>& p : players)
		p->tick();

	const int scrambleTicks = TurboServer::get()->getConfigManager().getServerConfig().playerListScrambleTicks;
	if (scrambleTicks > 0 && TurboServer::get()->getTicker().getTickCount() % scrambleTicks == 0)
		scramble();
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


int PlayerList::getPlayerCount() const
{
	return players.size();
}


void PlayerList::addPlayer(std::unique_ptr<PlayerEntity>&& player)
{
	players.push_back(std::move(player));
}


void PlayerList::scramble()
{
	static std::random_device rd;
	static std::mt19937 rng(rd());
	std::ranges::shuffle(players, rng);
}
