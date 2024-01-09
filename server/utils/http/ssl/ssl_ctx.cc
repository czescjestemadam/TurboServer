#include "ssl_ctx.hh"

SslCtx::SslCtx()
{
	ctx = SSL_CTX_new(TLS_method());
}

SslCtx::~SslCtx()
{
	if (ctx)
		SSL_CTX_free(ctx);
}

bool SslCtx::isValid() const
{
	return ctx != nullptr;
}

SSL_CTX* SslCtx::get() const
{
	return ctx;
}
