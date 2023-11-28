#pragma once
#include "socket.hh"

#include <sys/epoll.h>

class EpollSocket : public Socket
{
	static constexpr int EPOLL_FLAGS = 0;
	static constexpr int EVENTS = 32;
	static constexpr int TIMEOUT = 5000;

public:
	void create() override;

	void add(const Socket& sock, int events = EPOLLIN);
	void remove(const Socket& sock);

	std::vector<epoll_event> wait();
};
