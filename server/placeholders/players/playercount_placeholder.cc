#include "playercount_placeholder.hh"

#include "server/turbo_server.hh"

std::string PlayercountPlaceholder::getName()
{
	return "playercount";
}

std::string PlayercountPlaceholder::getReplacement()
{
	return std::to_string(TurboServer::get()->getPlayerList().getPlayerCount());
}

std::string PlayercountPlaceholder::getReplacementFor(PlayerEntity* player)
{
	return getReplacement(); // todo only visible
}
