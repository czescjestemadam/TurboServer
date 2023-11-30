#pragma once
#include "packet_handler.hh"
#include "../../socket/player_socket.hh"

class StatusPacketHandler : public PacketHandler
{
public:
	explicit StatusPacketHandler(PlayerSocket* sock);

	void handle(Packet& packet) override;
	void disconnect(ChatComponent* chat) override;

private:
	void handleStatusReq(Packet& packet);
	void handlePingReq(Packet& packet);
};
