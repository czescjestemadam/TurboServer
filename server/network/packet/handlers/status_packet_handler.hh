#pragma once
#include "packet_handler.hh"
#include "../../socket/player_socket.hh"

class StatusPacketHandler : public PacketHandler
{
public:
	void handle(PlayerSocket* sock, Packet& packet) override;
	void disconnect(PlayerSocket* sock, ChatComponent* chat) override;

private:
	void handleStatusReq(PlayerSocket* sock, Packet& packet);
	void handlePingReq(PlayerSocket* sock, Packet& packet);
};
