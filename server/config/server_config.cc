#include "server_config.hh"

#include "json_helper.hh"

void ServerConfig::load(nlohmann::json&& j)
{
	JSON_HELPER_READ(gamemode)
	JSON_HELPER_READ(forceGamemode)

	JSON_HELPER_READ(allowFlight)
	JSON_HELPER_READ(enableCommandBlock)
	JSON_HELPER_READ(pvp)
	JSON_HELPER_READ(difficulty)
	JSON_HELPER_READ(maxTickTime)
	JSON_HELPER_READ(maxPlayers)
	JSON_HELPER_READ(onlineMode)

	JSON_HELPER_READ(enableStatus)
	JSON_HELPER_READ(statusPlayerCount)
	JSON_HELPER_READ(hideOnlinePlayers)
	JSON_HELPER_READ(motd)

	JSON_HELPER_READ(viewDistance)
	JSON_HELPER_READ(simulationDistnace)
	JSON_HELPER_READ(entityBroadcastRangePercentage)

	JSON_HELPER_READ(playerIdleTimeout)
	JSON_HELPER_READ(hardcore)

	JSON_HELPER_READ(serverClosedMessage)
	JSON_HELPER_READ(serverRestartMessage)
	JSON_HELPER_READ(serverFullMessage)
	JSON_HELPER_READ(notWhitelistedMessage)
	JSON_HELPER_READ(outdatedClientMessage)
	JSON_HELPER_READ(outdatedServerMessage)

	JSON_HELPER_READ(disableStats)
	JSON_HELPER_READ(disableAdvancements)

	JSON_HELPER_READ(joinMessages)
	JSON_HELPER_READ(joinMessageFormat)
	JSON_HELPER_READ(quitMessages)
	JSON_HELPER_READ(quitMessageFormat)
	JSON_HELPER_READ(quitMessageUseDisplayname)
}

nlohmann::json ServerConfig::save()
{
	nlohmann::json j;

	JSON_HELPER_WRITE(gamemode)
	JSON_HELPER_WRITE(forceGamemode)

	JSON_HELPER_WRITE(allowFlight)
	JSON_HELPER_WRITE(enableCommandBlock)
	JSON_HELPER_WRITE(pvp)
	JSON_HELPER_WRITE(difficulty)
	JSON_HELPER_WRITE(maxTickTime)
	JSON_HELPER_WRITE(maxPlayers)
	JSON_HELPER_WRITE(onlineMode)

	JSON_HELPER_WRITE(enableStatus)
	JSON_HELPER_WRITE(statusPlayerCount)
	JSON_HELPER_WRITE(hideOnlinePlayers)
	JSON_HELPER_WRITE(motd)

	JSON_HELPER_WRITE(viewDistance)
	JSON_HELPER_WRITE(simulationDistnace)
	JSON_HELPER_WRITE(entityBroadcastRangePercentage)

	JSON_HELPER_WRITE(playerIdleTimeout)
	JSON_HELPER_WRITE(hardcore)

	JSON_HELPER_WRITE(serverClosedMessage)
	JSON_HELPER_WRITE(serverRestartMessage)
	JSON_HELPER_WRITE(serverFullMessage)
	JSON_HELPER_WRITE(notWhitelistedMessage)
	JSON_HELPER_WRITE(outdatedClientMessage)
	JSON_HELPER_WRITE(outdatedServerMessage)

	JSON_HELPER_WRITE(disableStats)
	JSON_HELPER_WRITE(disableAdvancements)

	JSON_HELPER_WRITE(joinMessages)
	JSON_HELPER_WRITE(joinMessageFormat)
	JSON_HELPER_WRITE(quitMessages)
	JSON_HELPER_WRITE(quitMessageFormat)
	JSON_HELPER_WRITE(quitMessageUseDisplayname)

	return j;
}

std::string ServerConfig::getName()
{
	return "server";
}
