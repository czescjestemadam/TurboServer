#include "handshaking_packet_handler.hh"

void HandshakingPacketHandler::handle(PlayerSocket* sock, Packet& packet)
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

void HandshakingPacketHandler::disconnect(PlayerSocket* sock, ChatComponent* chat)
{
}
