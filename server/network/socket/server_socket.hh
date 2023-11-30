#pragma once
#include "socket.hh"
#include "player_socket.hh"

class ServerSocket : public Socket
{
	static constexpr int LISTEN_QUEUE_SIZE = 64;

public:
	void bind(const std::string& ip, short port);
	void listen();

	PlayerSocket accept();

	void forceClose();
};
