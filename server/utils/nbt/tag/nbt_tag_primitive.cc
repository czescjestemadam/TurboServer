#include "nbt_tag_primitive.hh"

// byte
NbtTagByte::NbtTagByte(byte_t val) : NbtTagPrimitive(val)
{
}

std::unique_ptr<NbtTag> NbtTagByte::copy()
{
	return std::make_unique<NbtTagByte>(val);
}

void NbtTagByte::write(PacketBuff& buff)
{
	buff.writeByte(val);
}

NbtTagType NbtTagByte::getType()
{
	return BYTE;
}

int NbtTagByte::getSizeBytes()
{
	return 9;
}

// short
NbtTagShort::NbtTagShort(short val) : NbtTagPrimitive(val)
{
}

std::unique_ptr<NbtTag> NbtTagShort::copy()
{
	return std::make_unique<NbtTagShort>(val);
}

void NbtTagShort::write(PacketBuff& buff)
{
	buff.writeShort(val);
}

NbtTagType NbtTagShort::getType()
{
	return SHORT;
}

int NbtTagShort::getSizeBytes()
{
	return 10;
}

// int
NbtTagInt::NbtTagInt(int val) : NbtTagPrimitive(val)
{
}

std::unique_ptr<NbtTag> NbtTagInt::copy()
{
	return std::make_unique<NbtTagInt>(val);
}

void NbtTagInt::write(PacketBuff& buff)
{
	buff.writeInt(val);
}

NbtTagType NbtTagInt::getType()
{
	return INT;
}

int NbtTagInt::getSizeBytes()
{
	return 12;
}

// long
NbtTagLong::NbtTagLong(long val) : NbtTagPrimitive(val)
{
}

std::unique_ptr<NbtTag> NbtTagLong::copy()
{
	return std::make_unique<NbtTagLong>(val);
}

void NbtTagLong::write(PacketBuff& buff)
{
	buff.writeLong(val);
}

NbtTagType NbtTagLong::getType()
{
	return LONG;
}

int NbtTagLong::getSizeBytes()
{
	return 16;
}

// float
NbtTagFloat::NbtTagFloat(float val) : NbtTagPrimitive(val)
{
}

std::unique_ptr<NbtTag> NbtTagFloat::copy()
{
	return std::make_unique<NbtTagFloat>(val);
}

void NbtTagFloat::write(PacketBuff& buff)
{
	buff.writeFloat(val);
}

NbtTagType NbtTagFloat::getType()
{
	return FLOAT;
}

int NbtTagFloat::getSizeBytes()
{
	return 12;
}

// double
NbtTagDouble::NbtTagDouble(double val) : NbtTagPrimitive(val)
{
}

std::unique_ptr<NbtTag> NbtTagDouble::copy()
{
	return std::make_unique<NbtTagDouble>(val);
}

void NbtTagDouble::write(PacketBuff& buff)
{
	buff.writeFloat((float)val);
}

NbtTagType NbtTagDouble::getType()
{
	return DOUBLE;
}

int NbtTagDouble::getSizeBytes()
{
	return 16;
}

// string
NbtTagString::NbtTagString(const std::string& val) : NbtTagPrimitive(val)
{
}

std::unique_ptr<NbtTag> NbtTagString::copy()
{
	return std::make_unique<NbtTagString>(val);
}

void NbtTagString::write(PacketBuff& buff)
{
	buff.writeString(val);
}

NbtTagType NbtTagString::getType()
{
	return STRING;
}

int NbtTagString::getSizeBytes()
{
	return 36 + 2 * val.length();
}

