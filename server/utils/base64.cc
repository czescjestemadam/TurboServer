#include "base64.hh"

constexpr const char* CHARS = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789+/";

std::string Base64::encode(const byte_t* bytes, ulong len)
{
	const ulong outLen = encodedLen(len);

	std::string out;
	out.reserve(outLen);

	uint idx = 0;
	while (idx < len)
	{
		out += CHARS[(bytes[idx] & 0xfc) >> 2];

		if (idx + 1 < len)
		{
			out += CHARS[((bytes[idx] & 0x03) << 4) + ((bytes[idx + 1] & 0xf0) >> 4)];

			if (idx + 2 < len)
			{
				out += CHARS[((bytes[idx + 1] & 0x0f) << 2) + ((bytes[idx + 2] & 0xc0) >> 6)];
				out += CHARS[bytes[idx + 2] & 0x3f];
			}
			else
			{
				out += CHARS[(bytes[idx + 1] & 0x0f) << 2];
				out += '=';
			}
		}
		else
		{
			out += CHARS[(bytes[idx] & 0x03) << 4];
			out += "==";
		}

		idx += 3;
	}

	return out;
}

std::string Base64::encode(const std::string& str)
{
	return encode((byte_t*)str.data(), str.size());
}

std::string Base64::encode(const std::vector<byte_t>& bytes)
{
	return encode(bytes.data(), bytes.size());
}

ulong Base64::encodedLen(ulong len)
{
	return (len + 2) / 3 * 4;
}


std::string Base64::decode(const std::string& str)
{
	return ""; // todo
}
