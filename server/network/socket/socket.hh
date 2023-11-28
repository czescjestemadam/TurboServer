#pragma once
#include <string>
#include <arpa/inet.h>
#include "../../utils/logger/logger.hh"

class Socket
{
protected:
	int fd = -1;
	sockaddr_in addr{};

public:
	virtual void create();
	void close() const;

	int getFd() const;
	bool isValid() const;

	std::string getAddress() const;
	uint getAddressI() const;

	bool operator==(const Socket& rhs) const;
	bool operator!=(const Socket& rhs) const;
};
