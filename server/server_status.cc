#include "server_status.hh"
#include "turbo_server.hh"
#include "lib/json.hpp"
#include "utils/base64.hh"

void ServerStatus::loadIcon()
{
	icon.load("server-icon.png");
	if (icon.width != 64 || icon.height != 64)
	{
		icon = {};
		// todo warning or sth
	}
}

void ServerStatus::update()
{
	const ProtocolVersion& ver = TurboServer::getProtocolVersion();
	const ServerConfig& cfg = TurboServer::get()->getConfigManager().getServerConfig();

	nlohmann::json j;
	j["version"] = {
		{ "name",     ver.getName() },
		{ "protocol", ver.getNum() }
	};
	j["players"] = {
		{ "max",    cfg.maxPlayers },
		{ "online", TurboServer::get()->getPlayerList().getPlayerCount() },
		{ "sample", {}} // todo
	};
	j["description"] = {
		{ "text", cfg.motd }
	};

	if (icon.isValid())
		j["favicon"] = "data:image/png;base64," + Base64::encode(icon.bytes);

	json = j.dump();
}

const std::string& ServerStatus::getJson() const
{
	return json;
}
