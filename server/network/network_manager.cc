#include "network_manager.hh"
#include "socket/socket_exception.hh"
#include "socket/socket_closed_exception.hh"

void NetworkManager::start(const std::string& ip, short port)
{
	logger.info("Starting on {}:{}", ip, port);
	running = true;

	epollSocket.create();

	epollWaitThread = std::thread(std::bind(&NetworkManager::epollWaitLoop, this));

	serverSocket.create();
	serverSocket.bind(ip, port);
	serverSocket.listen();

	accepterThread = std::thread(std::bind(&NetworkManager::acceptLoop, this));
}

void NetworkManager::stop()
{
	logger.info("Stopping");
	running = false;

	serverSocket.forceClose();
	accepterThread.join();

	epollSocket.close();
	epollWaitThread.join();

	ChatComponent serverStopComponent;
	for (PlayerSocket& sock : players)
	{
		sock.handler->disconnect(&serverStopComponent);
		sock.close();
	}
}

void NetworkManager::tick()
{
	for (PlayerSocket& sock : players)
		sock.tick();
}

PlayerSocket* NetworkManager::getPlayerSocket(int fd)
{
	for (PlayerSocket& sock : players)
		if (sock.getFd() == fd)
			return &sock;

	return nullptr;
}

void NetworkManager::removePlayerSocket(PlayerSocket* sock)
{
	epollSocket.remove(*sock);
	sock->close();
	std::erase(players, *sock);
}

void NetworkManager::broadcastPacket(Packet& packet)
{
	for (PlayerSocket& sock : players)
		sock.write(packet);
}


void NetworkManager::acceptLoop()
{
	while (running)
	{
		try
		{
			PlayerSocket sock = serverSocket.accept();
			if (!running)
				return;

			sock.setOptions();

			logger.debug("accepted {}", sock.getAddress());

			epollSocket.add(sock);
			players.push_back(std::move(sock));
		}
		catch (SocketException& e)
		{
			logger.error(e.what());
		}
	}
}

void NetworkManager::epollWaitLoop()
{
	while (running)
	{
		std::vector<epoll_event> events = epollSocket.wait();
		for (epoll_event& e : events)
		{
			const uint ev = e.events;

			if (ev & EPOLLIN)
			{
				const int fd = e.data.fd;

				PlayerSocket* sock = getPlayerSocket(fd);
				if (sock)
					handleSocketData(sock);
				else
					logger.error("PlayerSocket {} not found", fd);
			}
			else
				logger.error("Unknown epoll event: {}", ev);
		}
	}
}

void NetworkManager::handleSocketData(PlayerSocket* sock)
{
	try
	{
		PacketBuff buff = sock->read();
		int field2 = buff.readVarint(); // packetId / uncompressed data len

		// todo remove
		logger.debug("packet from {0} state {1}: f2:{2}/0x{2:x} {3}",
				sock->getAddress(), (int)sock->state, field2, buff.toStringShort());

		// todo recode
		if (sock->compressionEnabled) // after SetCompression packet
		{
			if (field2 == 0) // compression disabled
			{
				int id = buff.readVarint();
				handlePacket(sock, { id, std::move(buff) });
			}
			else // compression enabled
			{
				PacketBuff decompressed = buff.decompress(field2);
				int id = decompressed.readVarint();
				handlePacket(sock, { id, std::move(decompressed) });
			}
		}
		else // pre SetCompression packet
		{
			handlePacket(sock, { field2, std::move(buff) });
		}
	}
	catch (const SocketClosedException& e)
	{
		logger.error("socket closed {}: {}", sock->getAddress(), e.what());
		removePlayerSocket(sock);
	}
	catch (const std::exception& e)
	{
		logger.error("socket {}: {}", sock->getAddress(), e.what());
		removePlayerSocket(sock);
	}
}

void NetworkManager::handlePacket(PlayerSocket* sock, Packet&& packet)
{
	try
	{
		sock->handler->handle(packet);
	}
	catch (std::exception& e)
	{
		logger.error("error handling state/packet {}/{}: {}", (int)sock->state, packet.getId(), e.what());
	}
}
