#include "epoll_socket.hh"
#include "socket_exception.hh"

#include <sys/epoll.h>

void EpollSocket::create()
{
	if (fd < 0)
		fd = epoll_create1(EPOLL_FLAGS);
}


void EpollSocket::add(const Socket& sock, int events)
{
	epoll_event e{};
	e.events = events;
	e.data.fd = sock.getFd();

	if (epoll_ctl(fd, EPOLL_CTL_ADD, sock.getFd(), &e) < 0)
		throw SocketException("error adding socket " + sock.getAddress());
}

void EpollSocket::remove(const Socket& sock)
{
	if (epoll_ctl(fd, EPOLL_CTL_DEL, sock.getFd(), nullptr) < 0)
		throw SocketException("error removing socket " + sock.getAddress());
}

std::vector<epoll_event> EpollSocket::wait()
{
	epoll_event e[EVENTS];

	const int eventsNo = epoll_wait(fd, e, EVENTS, TIMEOUT);
	if (eventsNo < 0 && errno == EINTR)
		throw SocketException("error waiting epoll socket " + getAddress());

	return { e, e + eventsNo };
}
