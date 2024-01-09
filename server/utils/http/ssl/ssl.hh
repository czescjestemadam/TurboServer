#pragma once
#include "ssl_ctx.hh"

#include <string>

class Ssl
{
	SslCtx ctx;

	SSL* ssl = nullptr;

public:
	Ssl();
	~Ssl();

	void setFd(int fd);
	void connect();
	void write(const std::string& str);
	void read(char* buf, int len);

	SslCtx& getCtx();
};
