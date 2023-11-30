#include "status_packet_handler.hh"

#include "server/turbo_server.hh"

StatusPacketHandler::StatusPacketHandler(PlayerSocket* sock) : PacketHandler(sock)
{
}

void StatusPacketHandler::handle(Packet& packet)
{
	switch (packet.getId())
	{
		case PacketId::Status::STATUS_REQUEST:
			handleStatusReq(packet);
			break;

		case PacketId::Status::PING_REQUEST:
			handlePingReq(packet);
			break;
	}
}

void StatusPacketHandler::disconnect(ChatComponent* chat)
{
}


void StatusPacketHandler::handleStatusReq(Packet& packet)
{
	const ProtocolVersion& ver = TurboServer::getProtocolVersion();
	const ServerConfig& sCfg = TurboServer::get()->getConfigManager().getServerConfig();

	nlohmann::json j;
	j["version"] = {
			{ "name",     ver.getName() },
			{ "protocol", ver.getNum() }
	};
	j["players"] = {
			{ "max",    sCfg.maxPlayers },
			{ "online", -1 }, // todo
			{ "sample", {}}
	};
	j["description"] = {
			{ "text", sCfg.motd }
	};

	PacketBuff data;
	data.writeString(j.dump());
	sock->write({ PacketId::Status::STATUS_RESPONSE, std::move(data) });
}

void StatusPacketHandler::handlePingReq(Packet& packet)
{
	sock->write(packet);
}
