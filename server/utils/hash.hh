#pragma once

typedef unsigned char byte_t;

namespace Hash
{
	void md5(byte_t* bytes, unsigned long len, byte_t out[16]);
}
