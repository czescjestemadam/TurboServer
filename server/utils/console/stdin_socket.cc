#include "stdin_socket.hh"

#include <unistd.h>

StdinSocket::StdinSocket()
{
	fd = STDIN_FILENO;
}
