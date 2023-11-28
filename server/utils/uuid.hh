#pragma once
#include <string>

typedef unsigned char byte_t;

class UUID
{
	union
	{
		byte_t bytes[16];

		struct
		{
			ulong hi, lo;
		};
	};

public:
	UUID() = default;
	UUID(ulong hi, ulong lo);

	int getVersion();
	void setVersion(int version);

	bool isNil() const;

	std::string toString() const;
	std::string toStringShort() const;

	ulong getHi() const;
	ulong getLo() const;

	bool operator==(const UUID& rhs) const;
	bool operator!=(const UUID& rhs) const;

	static UUID random();
	static UUID parse(const std::string& str);
	static UUID fromString(const std::string& str);
	static UUID nil();

private:
	static int hexValue(char c);
};
