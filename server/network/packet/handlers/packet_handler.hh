#pragma once
#include "../packet.hh"
#include "server/chat/chat_component.hh"

class PlayerSocket;

class PacketHandler
{
protected:
	PlayerSocket* sock;

public:
	explicit PacketHandler(PlayerSocket* sock) : sock(sock)
	{
	}

	virtual ~PacketHandler() = default;

	virtual void handle(Packet& packet) = 0;
	virtual void disconnect(ChatComponent* chat) = 0;
};
