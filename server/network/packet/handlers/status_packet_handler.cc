#include "status_packet_handler.hh"
#include "../packet_id.hh"

#include "server/turbo_server.hh"

void StatusPacketHandler::handle(PlayerSocket* sock, Packet& packet)
{
	switch (packet.getId())
	{
		case PacketId::Status::STATUS_REQUEST:
			handleStatusReq(sock, packet);
			break;

		case PacketId::Status::PING_REQUEST:
			handlePingReq(sock, packet);
			break;
	}
}

void StatusPacketHandler::disconnect(PlayerSocket* sock, ChatComponent* chat)
{
}


void StatusPacketHandler::handleStatusReq(PlayerSocket* sock, Packet& packet)
{
	PacketBuff data;
	data.writeString(TurboServer::get()->getStatus().getJson());
	sock->write({ PacketId::Status::STATUS_RESPONSE, std::move(data) });
}

void StatusPacketHandler::handlePingReq(PlayerSocket* sock, Packet& packet)
{
	sock->write(packet);
}
