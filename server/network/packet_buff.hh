#pragma once
#include "../utils/uuid.hh"
#include "server/utils/identifier.hh"
#include "server/utils/vec.hh"

#include <deque>
#include <vector>
#include <string>

typedef unsigned char byte_t;

class PacketBuff
{
	std::vector<byte_t> buff;

public:
	PacketBuff() = default;
	PacketBuff(byte_t* bytes, ulong size);

	byte_t readByte();
	void writeByte(byte_t v);

	void readBytes(byte_t* v, ulong len);
	void writeBytes(byte_t* v, ulong len);

	PacketBuff readBuff(ulong len);
	void writeBuff(const PacketBuff& b);

	short readShort();
	void writeShort(short v);

	int readInt();
	void writeInt(int v);

	int readVarint();
	void writeVarint(int v);

	long readLong();
	void writeLong(long v);

	ulong readLongU();
	void writeLongU(ulong v);

	long readVarlong();
	void writeVarlong(long v);

	float readFloat();
	void writeFloat(float v);

	double readDouble();
	void writeDouble(double v);

	std::string readString();
	void writeString(const std::string& v);

	// todo chat

	Identifier readIdentifier();
	void writeIdentifier(const Identifier& v);

	// todo entity metadata
	// todo slot
	// todo nbt

	Vec3i readPosition();
	void writePosition(Vec3i v);

	float readAngle();
	void writeAngle(float v);

	UUID readUUID();
	void writeUUID(const UUID& v);

	/**
	 * level: \n
	 * -1  = default \n
	 * 0   = disabled \n
	 * 1-9 = speed-compression
	 */
	PacketBuff compress(int level);
	PacketBuff decompress(ulong dstLen);

	byte_t* data();
	ulong size() const;

	std::string toString() const;
	std::string toStringShort() const;

private:
	static void checkZlibReturnCode(int ret);
};
