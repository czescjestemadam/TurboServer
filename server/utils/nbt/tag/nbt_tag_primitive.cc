#include "nbt_tag_primitive.hh"

#include <netinet/in.h>

// byte
NbtTagByte::NbtTagByte(const std::string& name, byte_t val) : NbtTagPrimitive(name, val)
{
}

std::unique_ptr<NbtTag> NbtTagByte::copy()
{
	return std::make_unique<NbtTagByte>(name, val);
}

void NbtTagByte::read(PacketBuff& buff, bool name)
{
	if (name)
		readName(buff);
	val = buff.readByte();
}

void NbtTagByte::write(PacketBuff& buff, bool name)
{
	if (name)
	{
		buff.writeByte(getType());
		writeName(buff);
	}

	buff.writeByte(val);
}

NbtTagType NbtTagByte::getType()
{
	return BYTE;
}

// short
NbtTagShort::NbtTagShort(const std::string& name, short val) : NbtTagPrimitive(name, val)
{
}

std::unique_ptr<NbtTag> NbtTagShort::copy()
{
	return std::make_unique<NbtTagShort>(name, val);
}

void NbtTagShort::read(PacketBuff& buff, bool name)
{
	if (name)
		readName(buff);
	val = buff.readShort();
}

void NbtTagShort::write(PacketBuff& buff, bool name)
{
	if (name)
	{
		buff.writeByte(getType());
		writeName(buff);
	}

	buff.writeShort(val);
}

NbtTagType NbtTagShort::getType()
{
	return SHORT;
}

// int
NbtTagInt::NbtTagInt(const std::string& name, int val) : NbtTagPrimitive(name, val)
{
}

std::unique_ptr<NbtTag> NbtTagInt::copy()
{
	return std::make_unique<NbtTagInt>(name, val);
}

void NbtTagInt::read(PacketBuff& buff, bool name)
{
	if (name)
		readName(buff);
	val = buff.readInt();
}

void NbtTagInt::write(PacketBuff& buff, bool name)
{
	if (name)
	{
		buff.writeByte(getType());
		writeName(buff);
	}

	buff.writeInt(val);
}

NbtTagType NbtTagInt::getType()
{
	return INT;
}

// long
NbtTagLong::NbtTagLong(const std::string& name, long val) : NbtTagPrimitive(name, val)
{
}

std::unique_ptr<NbtTag> NbtTagLong::copy()
{
	return std::make_unique<NbtTagLong>(name, val);
}

void NbtTagLong::read(PacketBuff& buff, bool name)
{
	if (name)
		readName(buff);
	val = buff.readLong();
}

void NbtTagLong::write(PacketBuff& buff, bool name)
{
	if (name)
	{
		buff.writeByte(getType());
		writeName(buff);
	}

	buff.writeLong(val);
}

NbtTagType NbtTagLong::getType()
{
	return LONG;
}

// float
NbtTagFloat::NbtTagFloat(const std::string& name, float val) : NbtTagPrimitive(name, val)
{
}

std::unique_ptr<NbtTag> NbtTagFloat::copy()
{
	return std::make_unique<NbtTagFloat>(name, val);
}

void NbtTagFloat::read(PacketBuff& buff, bool name)
{
	if (name)
		readName(buff);
	val = buff.readFloat();
}

void NbtTagFloat::write(PacketBuff& buff, bool name)
{
	if (name)
	{
		buff.writeByte(getType());
		writeName(buff);
	}

	buff.writeFloat(val);
}

NbtTagType NbtTagFloat::getType()
{
	return FLOAT;
}

// double
NbtTagDouble::NbtTagDouble(const std::string& name, double val) : NbtTagPrimitive(name, val)
{
}

std::unique_ptr<NbtTag> NbtTagDouble::copy()
{
	return std::make_unique<NbtTagDouble>(name, val);
}

void NbtTagDouble::read(PacketBuff& buff, bool name)
{
	if (name)
		readName(buff);
	val = buff.readDouble();
}

void NbtTagDouble::write(PacketBuff& buff, bool name)
{
	if (name)
	{
		buff.writeByte(getType());
		writeName(buff);
	}

	buff.writeDouble(val);
}

NbtTagType NbtTagDouble::getType()
{
	return DOUBLE;
}

// string
NbtTagString::NbtTagString(const std::string& name, const std::string& val) : NbtTagPrimitive(name, val)
{
}

std::unique_ptr<NbtTag> NbtTagString::copy()
{
	return std::make_unique<NbtTagString>(name, val);
}

void NbtTagString::read(PacketBuff& buff, bool name)
{
	if (name)
		readName(buff);

	const ushort len = ntohs(buff.readShortU());

	char cstr[len + 1];
	buff.readBytes(reinterpret_cast<byte_t*>(cstr), len);
	cstr[len] = 0;

	val = cstr;
}

void NbtTagString::write(PacketBuff& buff, bool name)
{
	if (name)
	{
		buff.writeByte(getType());
		writeName(buff);
	}

	writeStr(buff, val);
}

NbtTagType NbtTagString::getType()
{
	return STRING;
}

