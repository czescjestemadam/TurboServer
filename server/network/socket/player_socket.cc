#include "player_socket.hh"
#include "../varint_exception.hh"
#include "socket_closed_exception.hh"
#include "../packet/handlers/handshaking_packet_handler.hh"
#include "server/network/packet/handlers/status_packet_handler.hh"
#include "server/network/packet/handlers/login_packet_handler.hh"
#include "server/network/packet/handlers/play_packet_handler.hh"

#include <unistd.h>

PlayerSocket::PlayerSocket(int fd, sockaddr_in addr)
{
	this->fd = fd;
	this->addr = addr;
	this->setState(HANDSHAKING);
}

PacketBuff PlayerSocket::read()
{
	ulong len = readVarInt();
	byte_t bytes[len];
	checkReturnCode(::read(fd, bytes, len), "PlayerSocket::read()");
	++packetsReceived;

	return { bytes, len };
}

void PlayerSocket::write(PacketBuff& buff)
{
	PacketBuff toSend;
	toSend.writeVarint((int)buff.size());
	toSend.writeBuff(buff);
	checkReturnCode(send(fd, toSend.data(), toSend.size(), MSG_DONTWAIT), "PlayerSocket::write(PacketBuff& buff)");
}

void PlayerSocket::write(Packet& packet)
{
	PacketBuff toSend;

	if (compressionEnabled) // post SetCompression packet
	{
		PacketBuff data;
		data.writeVarint(packet.getId());
		data.writeBuff(packet.getData());

		int dataLen = (int)data.size();

		if (dataLen < compressionThreshold) // uncompressed
		{
			toSend.writeVarint(0);
			toSend.writeBuff(data);
		}
		else // compressed
		{
			toSend.writeVarint(dataLen);
			toSend.writeBuff(data.compress(-1));
		}
	}
	else // pre SetCompression packet
	{
		toSend.writeVarint(packet.getId());
		toSend.writeBuff(packet.getData());
	}

	write(toSend);
	++packetsSent;
}

void PlayerSocket::write(Packet&& packet)
{
	write(packet);
}

void PlayerSocket::tick()
{
	age++;
}

void PlayerSocket::setOptions()
{
	int v = 1;
	setsockopt(fd, SOL_SOCKET, SO_KEEPALIVE, &v, sizeof(v));
}

void PlayerSocket::setState(NetworkState next)
{
	state = next;
	switch (state)
	{
		case HANDSHAKING:
			handler = std::make_unique<HandshakingPacketHandler>(this);
			break;

		case STATUS:
			handler = std::make_unique<StatusPacketHandler>(this);
			break;

		case LOGIN:
			handler = std::make_unique<LoginPacketHandler>(this);
			break;

		case PLAY:
			handler = std::make_unique<PlayPacketHandler>(this);
			break;

		default:
			break;
	}
}


byte_t PlayerSocket::readByte()
{
	byte_t b[1];
	checkReturnCode(::read(fd, b, 1), "PlayerSocket::readByte()");
	return b[0];
}

int PlayerSocket::readVarInt()
{
	int val = 0;
	int pos = 0;
	byte_t cur;

	while (true)
	{
		cur = readByte();
		val |= (cur & 0x7f) << pos;

		if ((cur & 0x80) == 0)
			break;

		pos += 7;

		if (pos >= 32)
			throw VarintException("Varint too big");
	}

	return val;
}

void PlayerSocket::checkReturnCode(ulong ret, const std::string& func)
{
	if (ret < 0)
		throw SocketException(func);
	else if (ret == 0)
		throw SocketClosedException(func);
}
