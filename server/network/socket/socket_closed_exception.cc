#include "socket_closed_exception.hh"

SocketClosedException::SocketClosedException(const std::string& str) : SocketException(str)
{
}
