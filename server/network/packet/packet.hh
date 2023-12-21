#pragma once
#include "../packet_buff.hh"

static constexpr ulong PACKET_SIZE_LIMIT = 2097151;

class Packet
{
protected:
	int id = -1;
	PacketBuff data;

public:
	Packet(int id, PacketBuff&& data);

	int getId() const;
	PacketBuff& getData();
};
