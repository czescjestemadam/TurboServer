#pragma once
#include "iconfig.hh"

class ServerConfig : public IConfig
{
public:
	std::string gamemode = "survival";
	bool forceGamemode = false;

	bool allowFlight = false;
	bool enableCommandBlock = false;
	bool pvp = true;
	std::string difficulty = "easy";
	int maxTickTime = 60000;
	int maxPlayers = 33;
	bool onlineMode = true;

	// respond to server list pings
	bool enableStatus = true;
	int statusPlayerCount = 12;
	bool hideOnlinePlayers = false;
	std::string motd = "&aA Minecraft TurboServer";

	int viewDistance = 10;
	int simulationDistnace = 10;
	int entityBroadcastRangePercentage = 100;

	// afk ticks before kick
	int playerIdleTimeout = 0;
	bool hardcore = false;

	std::string serverClosedMessage = "Server closed";
	std::string serverRestartMessage = "Server is restarting";
	std::string serverFullMessage = "The server is full!";
	std::string notWhitelistedMessage = "You are not whitelisted on this server!";
	std::string outdatedClientMessage = "Outdated client! Please use {}";
	std::string outdatedServerMessage = "Outdated server! I'm still on {0}";

	bool disableStats = false;
	bool disableAdvancements = false;

	bool joinMessages = true;
	std::string joinMessageFormat = "";
	bool quitMessages = true;
	std::string quitMessageFormat = "";
	bool quitMessageUseDisplayname = false;


	void load(nlohmann::json&& j) override;
	nlohmann::json save() override;

	std::string getName() override;
};
