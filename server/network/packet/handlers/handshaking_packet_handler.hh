#pragma once
#include "packet_handler.hh"
#include "../../socket/player_socket.hh"

class HandshakingPacketHandler : public PacketHandler
{
public:
	void handle(PlayerSocket* sock, Packet& packet) override;
	void disconnect(PlayerSocket* sock, ChatComponent* chat) override;
};
