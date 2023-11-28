#include "network_config.hh"

#include "json_helper.hh"

void NetworkConfig::load(nlohmann::json&& j)
{
	JSON_HELPER_READ(compressionThreshold)
	JSON_HELPER_READ(compressionLevel)
	JSON_HELPER_READ(serverIp)
	JSON_HELPER_READ(serverPort)
	JSON_HELPER_READ(preventProxyConnections)
	JSON_HELPER_READ(rateLimit)
	JSON_HELPER_READ(rateLimitKickReason)
	JSON_HELPER_READ(connectionThrotleTicks)
	JSON_HELPER_READ(logIps)

	JSON_HELPER_READ(packetHandlingThreads)
	JSON_HELPER_READ(packetSenderThreads)
}

nlohmann::json NetworkConfig::save()
{
	nlohmann::json j;

	JSON_HELPER_WRITE(compressionThreshold)
	JSON_HELPER_WRITE(compressionLevel)
	JSON_HELPER_WRITE(serverIp)
	JSON_HELPER_WRITE(serverPort)
	JSON_HELPER_WRITE(preventProxyConnections)
	JSON_HELPER_WRITE(rateLimit)
	JSON_HELPER_WRITE(rateLimitKickReason)
	JSON_HELPER_WRITE(connectionThrotleTicks)
	JSON_HELPER_WRITE(logIps)

	JSON_HELPER_WRITE(packetHandlingThreads)
	JSON_HELPER_WRITE(packetSenderThreads)

	return j;
}

std::string NetworkConfig::getName()
{
	return "network";
}
