#include "packet.hh"


Packet::Packet(int id, PacketBuff&& data) : id(id), data(std::move(data))
{
}

int Packet::getId() const
{
	return id;
}

PacketBuff& Packet::getData()
{
	return data;
}
