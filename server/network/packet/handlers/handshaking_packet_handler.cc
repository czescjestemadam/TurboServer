#include "handshaking_packet_handler.hh"

#include "status_packet_handler.hh"

HandshakingPacketHandler::HandshakingPacketHandler(PlayerSocket* sock) : PacketHandler(sock)
{
}

void HandshakingPacketHandler::handle(Packet& packet)
{
	if (packet.getId() == PacketId::Handshaking::HANDSHAKE)
	{
		PacketBuff& data = packet.getData();
		sock->protocolVersion = ProtocolVersion::fromNum(data.readVarint());
		data.readString(); // addr
		data.readShort(); // port
		int nextState = data.readVarint();
		if (nextState == 1)
			sock->setState(STATUS);
		else if (nextState == 2)
			sock->setState(LOGIN);
	}
}

void HandshakingPacketHandler::disconnect(ChatComponent* chat)
{
}
