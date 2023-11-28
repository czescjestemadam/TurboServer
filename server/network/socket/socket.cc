#include "socket.hh"

#include <unistd.h>
#include <format>

void Socket::create()
{
	if (fd < 0)
		fd = socket(AF_INET, SOCK_STREAM, 0);
}

void Socket::close() const
{
	if (fd > 0)
		::close(fd);
}

int Socket::getFd() const
{
	return fd;
}

bool Socket::isValid() const
{
	return fd > 0;
}

std::string Socket::getAddress() const
{
	return std::format("{}:{}/{}", inet_ntoa(addr.sin_addr), ntohs(addr.sin_port), fd);
}

uint Socket::getAddressI() const
{
	return addr.sin_addr.s_addr;
}


bool Socket::operator==(const Socket& rhs) const
{
	return fd == rhs.fd;
}

bool Socket::operator!=(const Socket& rhs) const
{
	return !(rhs == *this);
}
