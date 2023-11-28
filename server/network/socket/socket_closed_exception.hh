#pragma once
#include "socket_exception.hh"

class SocketClosedException : public SocketException
{
public:
	explicit SocketClosedException(const std::string& str);
};
