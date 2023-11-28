#include "packet_buff.hh"

#include "varint_exception.hh"
#include "zlib_exception.hh"

#include <sstream>
#include <iomanip>
#include <zlib.h>

#define PACKETBUFF_READ(type) union \
{                                   \
    byte_t bs[sizeof(type)];        \
    type val;                       \
};                                  \
readBytes(bs, sizeof(type));        \
return val

#define PACKETBUFF_WRITE(type) union \
{                                    \
    byte_t bs[sizeof(type)];         \
    type val;                        \
};                                   \
val = v;                             \
writeBytes(bs, sizeof(type))

#define PACKETBUFF_WRITE_VAR(type) while (true)                \
{                                                            \
    if ((v & ~SEGMENT_BITS) == 0)                            \
    {                                                        \
        writeByte(byte_t(v));                                \
        return;                                                \
    }                                                        \
    writeByte(byte_t((v & SEGMENT_BITS) | CONTINUE_BIT));    \
    v = type(v) >> 7;                                        \
}

static constexpr int SEGMENT_BITS = 0x7f;
static constexpr int CONTINUE_BIT = 0x80;

PacketBuff::PacketBuff(byte_t* bytes, ulong size) : buff(bytes, bytes + size)
{
}

byte_t PacketBuff::readByte()
{
	byte_t b = buff.front();
	buff.erase(buff.begin());
	return b;
}

void PacketBuff::writeByte(byte_t v)
{
	buff.push_back(v);
}

void PacketBuff::readBytes(byte_t* v, ulong len)
{
	if (buff.size() < len)
		return;

	for (int i = 0; i < len; ++i)
		v[i] = readByte();
}

void PacketBuff::writeBytes(byte_t* v, ulong len)
{
	for (int i = 0; i < len; ++i)
		buff.push_back(v[i]);
}

PacketBuff PacketBuff::readBuff(ulong len)
{
	byte_t bytes[len];
	readBytes(bytes, len);

	return { bytes, len };
}

void PacketBuff::writeBuff(const PacketBuff& b)
{
	buff.insert(buff.end(), b.buff.begin(), b.buff.end());
}

short PacketBuff::readShort()
{
	PACKETBUFF_READ(short);
}

void PacketBuff::writeShort(short v)
{
	PACKETBUFF_WRITE(short);
}

int PacketBuff::readInt()
{
	PACKETBUFF_READ(int);
}

void PacketBuff::writeInt(int v)
{
	PACKETBUFF_WRITE(int);
}

int PacketBuff::readVarint()
{
	int val = 0;
	int pos = 0;
	byte_t cur;

	while (true)
	{
		cur = readByte();
		val |= (cur & SEGMENT_BITS) << pos;

		if ((cur & CONTINUE_BIT) == 0)
			break;

		pos += 7;

		if (pos >= 32)
			throw VarintException("Varint too big");
	}

	return val;
}

void PacketBuff::writeVarint(int v)
{
	PACKETBUFF_WRITE_VAR(uint);
}

long PacketBuff::readLong()
{
	PACKETBUFF_READ(long);
}

void PacketBuff::writeLong(long v)
{
	PACKETBUFF_WRITE(long);
}

ulong PacketBuff::readLongU()
{
	PACKETBUFF_READ(ulong);
}

void PacketBuff::writeLongU(ulong v)
{
	PACKETBUFF_WRITE(ulong);
}

long PacketBuff::readVarlong()
{
	long val = 0;
	int pos = 0;
	byte_t cur;

	while (true)
	{
		cur = readByte();
		val |= (long)(cur & SEGMENT_BITS) << pos;

		if ((cur & CONTINUE_BIT) == 0)
			break;

		pos += 7;

		if (pos >= 64)
			throw VarintException("Varlong too big");
	}

	return val;
}

void PacketBuff::writeVarlong(long v)
{
	PACKETBUFF_WRITE_VAR(ulong);
}

float PacketBuff::readFloat()
{
	PACKETBUFF_READ(float);
}

void PacketBuff::writeFloat(float v)
{
	PACKETBUFF_WRITE(float);
}

double PacketBuff::readDouble()
{
	PACKETBUFF_READ(double);
}

void PacketBuff::writeDouble(double v)
{
	PACKETBUFF_WRITE(double);
}

std::string PacketBuff::readString()
{
	const int len = readVarint();
	byte_t bs[len];
	readBytes(bs, len);

	return { bs, bs + len };
}

void PacketBuff::writeString(const std::string& v)
{
	writeVarint((int)v.length());
	writeBytes((byte_t*)v.data(), (int)v.length());
}

Identifier PacketBuff::readIdentifier()
{
	return { readString() };
}

void PacketBuff::writeIdentifier(const Identifier& v)
{
	writeString(v.toString());
}

Vec3i PacketBuff::readPosition()
{
	ulong l = readLongU();
	return Vec3i(l >> 38, l << 52 >> 52, l << 26 >> 48);
}

void PacketBuff::writePosition(Vec3i v)
{
	writeLongU(ulong(v.x & 0x3ffffff) << 38 | ulong(v.z & 0x3ffffff) << 12 | (v.y & 0xfff));
}

float PacketBuff::readAngle()
{
	byte_t b = readByte();
	return b / 256.f;
}

void PacketBuff::writeAngle(float v)
{
	writeByte(v / 256);
}

UUID PacketBuff::readUUID()
{
	const ulong hi = readLongU();
	const ulong lo = readLongU();
	return { hi, lo };
}

void PacketBuff::writeUUID(const UUID& v)
{
	writeLongU(v.getHi());
	writeLongU(v.getLo());
}


PacketBuff PacketBuff::compress(int level)
{
	ulong srcLen = buff.size();
	ulong dstLen = compressBound(srcLen);
	byte_t dst[dstLen];

	checkZlibReturnCode(compress2(dst, &dstLen, buff.data(), srcLen, level));

	return { dst, dstLen };
}

PacketBuff PacketBuff::decompress(ulong dstLen)
{
	ulong srcLen = buff.size();
	byte_t dst[dstLen];

	checkZlibReturnCode(uncompress(dst, &dstLen, buff.data(), srcLen));

	return { dst, dstLen };
}


byte_t* PacketBuff::data()
{
	return buff.data();
}

ulong PacketBuff::size() const
{
	return buff.size();
}

std::string PacketBuff::toString() const
{
	if (buff.empty())
		return "[]";

	std::ostringstream ss;
	for (byte_t b : buff)
		ss << "0x" << std::setw(2) << std::setfill('0') << std::hex << (short)b << ' ';

	std::string str = ss.str();
	str.erase(str.end() - 1);

	return '[' + str + ']';
}

std::string PacketBuff::toStringShort() const
{
	if (buff.empty())
		return "[]";

	std::ostringstream ss;
	for (byte_t b : buff)
		ss << std::setw(2) << std::setfill('0') << std::hex << (short)b;

	return '[' + ss.str() + ']';
}


void PacketBuff::checkZlibReturnCode(int ret)
{
	switch (ret)
	{
		case Z_MEM_ERROR:
			throw ZlibException("not enough memory");
		case Z_BUF_ERROR:
			throw ZlibException("output buffer too small");
		case Z_STREAM_ERROR:
			throw ZlibException("invalid compression level");

		default:
			return;
	}
}
