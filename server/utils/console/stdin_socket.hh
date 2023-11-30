#pragma once
#include "server/network/socket/socket.hh"

class StdinSocket : public Socket
{
public:
	StdinSocket();
};
