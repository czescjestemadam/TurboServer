#pragma once
#include <openssl/ssl.h>

class SslCtx
{
	SSL_CTX* ctx = nullptr;

public:
	SslCtx();
	~SslCtx();

	bool isValid() const;

	SSL_CTX* get() const;
};
