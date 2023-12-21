#pragma once
#include <string>
#include <vector>

typedef unsigned char byte_t;

namespace Base64
{
	std::string encode(const byte_t* bytes, ulong len);
	std::string encode(const std::string& str);
	std::string encode(const std::vector<byte_t>& bytes);

	ulong encodedLen(ulong len);

	std::string decode(const std::string& str);
}
