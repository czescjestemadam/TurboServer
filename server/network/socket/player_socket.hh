#pragma once
#include "socket.hh"
#include "../packet/packet.hh"
#include "server/network/protocol_version.hh"
#include "server/network/packet/handlers/packet_handler.hh"

#include <memory>

class PlayerEntity;
typedef unsigned char byte_t;

class PlayerSocket : public Socket
{
public:
	int age = 0;
	NetworkState state = UNKNOWN_STATE;
	bool compressionEnabled = false;
	int compressionThreshold = -1;
	uint packetsSent = 0;
	uint packetsReceived = 0;
	ProtocolVersion protocolVersion = ProtocolVersion::vUNKNOWN;
	std::unique_ptr<PacketHandler> handler;
	PlayerEntity* player = nullptr;


	PlayerSocket(int fd, sockaddr_in addr);

	PacketBuff read();
	void write(PacketBuff& buff);
	void write(Packet& packet);
	void write(Packet&& packet);

	void tick();

	void setOptions();

	void setState(NetworkState next);

private:
	byte_t readByte();
	int readVarInt();

	static void checkReturnCode(ulong ret, const std::string& func);
};
