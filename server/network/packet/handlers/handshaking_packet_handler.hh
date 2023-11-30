#pragma once
#include "packet_handler.hh"
#include "../../socket/player_socket.hh"

class HandshakingPacketHandler : public PacketHandler
{
public:
	explicit HandshakingPacketHandler(PlayerSocket* sock);

	void handle(Packet& packet) override;
	void disconnect(ChatComponent* chat) override;
};
