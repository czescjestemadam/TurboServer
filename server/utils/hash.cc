#include "hash.hh"

#include <openssl/md5.h>

void Hash::md5(byte_t* bytes, unsigned long len, byte_t out[16])
{
	::MD5(bytes, len, out);
}
