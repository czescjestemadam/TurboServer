#include "server_socket.hh"
#include "socket_exception.hh"

void ServerSocket::bind(const std::string& ip, short port)
{
	addr.sin_family = AF_INET;
	addr.sin_addr = { inet_addr(ip.c_str()) };
	addr.sin_port = htons(port);

	if (::bind(fd, reinterpret_cast<sockaddr*>(&addr), sizeof(addr)))
	{
		perror("bind");
		exit(1); // todo exceptions
	}
}

void ServerSocket::listen()
{
	if (::listen(fd, LISTEN_QUEUE_SIZE))
	{
		perror("listen");
		exit(1); // todo exceptions
	}
}

PlayerSocket ServerSocket::accept()
{
	sockaddr_in addr{};
	uint addrLen = sizeof(sockaddr);
	int playerFd = ::accept(fd, reinterpret_cast<sockaddr*>(&addr), &addrLen);

	if (!isValid())
		return { -1, {}};

	if (playerFd < 0)
		throw SocketException("::accept returned invalid fd: " + std::to_string(playerFd));

	return { playerFd, addr };
}

void ServerSocket::forceClose()
{
	close();

	// self connect to unblock ::accept
	Socket sock;
	sock.create();
	connect(sock.getFd(), reinterpret_cast<sockaddr*>(&addr), sizeof(addr));
	sock.close();
}
