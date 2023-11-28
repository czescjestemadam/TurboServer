#pragma once
#include "../utils/logger/logger.hh"
#include "socket/server_socket.hh"
#include "socket/epoll_socket.hh"
#include "socket/player_socket.hh"
#include "packet/handlers/packet_handler.hh"

#include <unordered_map>
#include <thread>

class NetworkManager
{
	Logger logger{ "NetworkManager" };
	bool running = false;

	EpollSocket epollSocket;
	std::thread epollWaitThread;

	ServerSocket serverSocket;
	std::thread accepterThread;

	std::vector<PlayerSocket> players;

public:
	void start(const std::string& ip, short port);
	void stop();

	void tick();

	PlayerSocket* getPlayerSocket(int fd);
	void removePlayerSocket(PlayerSocket* sock);

	void broadcastPacket(Packet& packet);

private:
	void acceptLoop();
	void epollWaitLoop(); // packets come from here

	void handleSocketData(PlayerSocket* sock);
	void handlePacket(PlayerSocket* sock, Packet&& packet);
};
