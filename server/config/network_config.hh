#pragma once
#include "iconfig.hh"

class NetworkConfig : public IConfig
{
public:
	int compressionThreshold = 256;
	int compressionLevel = -1;
	std::string serverIp = "0.0.0.0";
	short serverPort = 25565;
	bool preventProxyConnections = false;
	int rateLimit = 500;
	std::string rateLimitKickReason = "Packet rate limit exceeded!";
	// ticks before reconnect
	int connectionThrotleTicks = 60;
	bool logIps = true;

	int packetHandlingThreads = 2;
	int packetSenderThreads = 2;



	void load(nlohmann::json&& j) override;
	nlohmann::json save() override;

	std::string getName() override;
};
