#include "uuid.hh"
#include "hash.hh"

#include <random>
#include <format>

UUID::UUID(ulong hi, ulong lo) : hi(hi), lo(lo)
{
}


int UUID::getVersion()
{
	return bytes[6] >> 4;
}

void UUID::setVersion(int version)
{
	// version
	bytes[6] &= 0x0f;
	bytes[6] |= (version << 4) & 0xf0;
}


bool UUID::isNil() const
{
	return !hi && !lo;
}

std::string UUID::toString() const
{
	return std::format("{:02x}{:02x}{:02x}{:02x}-{:02x}{:02x}-{:02x}{:02x}-{:02x}{:02x}-{:02x}{:02x}{:02x}{:02x}{:02x}{:02x}",
			bytes[0], bytes[1], bytes[2], bytes[3],
			bytes[4], bytes[5],
			bytes[6], bytes[7],
			bytes[8], bytes[9],
			bytes[10], bytes[11], bytes[12], bytes[13], bytes[14], bytes[15]
	);
}

std::string UUID::toStringShort() const
{
	return std::format("{:02x}{:02x}{:02x}{:02x}{:02x}{:02x}{:02x}{:02x}{:02x}{:02x}{:02x}{:02x}{:02x}{:02x}{:02x}{:02x}",
			bytes[0], bytes[1], bytes[2], bytes[3],
			bytes[4], bytes[5],
			bytes[6], bytes[7],
			bytes[8], bytes[9],
			bytes[10], bytes[11], bytes[12], bytes[13], bytes[14], bytes[15]
	);
}

ulong UUID::getHi() const
{
	return hi;
}

ulong UUID::getLo() const
{
	return lo;
}


bool UUID::operator==(const UUID& rhs) const
{
	return hi == rhs.hi &&
		   lo == rhs.lo;
}

bool UUID::operator!=(const UUID& rhs) const
{
	return !(rhs == *this);
}


UUID UUID::random()
{
	static std::random_device rd;
	static std::mt19937_64 eng(rd());
	static std::uniform_int_distribution<ulong> dist;

	UUID id(dist(eng), dist(eng));
	id.setVersion(4);
	return id;
}

UUID UUID::parse(const std::string& str)
{
	if (str.length() > 36)
		return { 0, 0 };

	UUID id(0, 0);

	int idxB = 0;
	for (int i = 0; i < str.length(); i++)
	{
		char c = str.at(i);
		if (c == '-')
			continue;

		char c2 = str.at(++i);

		id.bytes[idxB++] = (hexValue(c) << 4) | hexValue(c2);
	}

	return id;
}

UUID UUID::fromString(const std::string& str)
{
	UUID id{};
	Hash::md5((byte_t*)str.c_str(), str.length(), id.bytes);

	id.setVersion(3);

	return id;
}

UUID UUID::nil()
{
	return { 0, 0 };
}


int UUID::hexValue(char c)
{
	switch (c)
	{
		default:
		case '0': return 0;
		case '1': return 1;
		case '2': return 2;
		case '3': return 3;
		case '4': return 4;
		case '5': return 5;
		case '6': return 6;
		case '7': return 7;
		case '8': return 8;
		case '9': return 9;
		case 'a': return 10;
		case 'b': return 11;
		case 'c': return 12;
		case 'd': return 13;
		case 'e': return 14;
		case 'f': return 15;
	}
}
