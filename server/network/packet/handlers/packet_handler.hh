#pragma once
#include "../packet.hh"
#include "server/chat/chat_component.hh"

class PlayerSocket;

class PacketHandler
{
public:
	virtual ~PacketHandler() = default;

	virtual void handle(PlayerSocket* sock, Packet& packet) = 0;
	virtual void disconnect(PlayerSocket* sock, ChatComponent* chat) = 0;
};
