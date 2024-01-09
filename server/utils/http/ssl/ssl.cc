#include "ssl.hh"

Ssl::Ssl()
{
	ssl = SSL_new(ctx.get());
}

Ssl::~Ssl()
{
	if (ssl)
		SSL_free(ssl);
}


void Ssl::setFd(int fd)
{
	SSL_set_fd(ssl, fd);
}

void Ssl::connect()
{
	SSL_connect(ssl); // todo error checking
}

void Ssl::write(const std::string& str)
{
	SSL_write(ssl, str.c_str(), static_cast<int>(str.length()));
}

void Ssl::read(char* buf, int len)
{
	SSL_read(ssl, buf, len);
}


SslCtx& Ssl::getCtx()
{
	return ctx;
}
