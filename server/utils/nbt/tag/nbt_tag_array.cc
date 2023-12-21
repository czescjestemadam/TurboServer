#include "nbt_tag_array.hh"

#include <netinet/in.h>

// byte
NbtTagByteArray::NbtTagByteArray(const std::string& name, const std::vector<byte_t>& arr) : NbtTagArray(name, arr)
{
}

std::unique_ptr<NbtTag> NbtTagByteArray::copy()
{
	return std::make_unique<NbtTagByteArray>(name, arr);
}

void NbtTagByteArray::read(PacketBuff& buff, bool name)
{
	if (name)
		readName(buff);

	const int len = ntohl(buff.readInt());

	byte_t bytes[len];
	buff.readBytes(bytes, len);

	arr = { bytes, bytes + len };
}

void NbtTagByteArray::write(PacketBuff& buff, bool name)
{
	if (name)
	{
		buff.writeByte(getType());
		writeName(buff);
	}

	buff.writeInt(htonl(arr.size()));
	buff.writeBytes(arr.data(), arr.size());
}

NbtTagType NbtTagByteArray::getType()
{
	return BYTE_ARRAY;
}

// int
NbtTagIntArray::NbtTagIntArray(const std::string& name, const std::vector<int>& arr) : NbtTagArray(name, arr)
{
}

std::unique_ptr<NbtTag> NbtTagIntArray::copy()
{
	return std::make_unique<NbtTagIntArray>(name, arr);
}

void NbtTagIntArray::read(PacketBuff& buff, bool name)
{
	if (name)
		readName(buff);

	const int len = buff.readInt();

	arr.reserve(len);
	for (int i = 0; i < len; ++i)
		arr.push_back(buff.readInt());
}

void NbtTagIntArray::write(PacketBuff& buff, bool name)
{
	if (name)
	{
		buff.writeByte(getType());
		writeName(buff);
	}

	buff.writeInt(htonl(arr.size()));
	for (const int v : arr)
		buff.writeInt(v);
}

NbtTagType NbtTagIntArray::getType()
{
	return INT_ARRAY;
}

// long
NbtTagLongArray::NbtTagLongArray(const std::string& name, const std::vector<long>& arr) : NbtTagArray(name, arr)
{
}

std::unique_ptr<NbtTag> NbtTagLongArray::copy()
{
	return std::make_unique<NbtTagLongArray>(name, arr);
}

void NbtTagLongArray::read(PacketBuff& buff, bool name)
{
	if (name)
		readName(buff);

	const int len = buff.readInt();

	arr.reserve(len);
	for (int i = 0; i < len; ++i)
		arr.push_back(buff.readLong());
}

void NbtTagLongArray::write(PacketBuff& buff, bool name)
{
	if (name)
	{
		buff.writeByte(getType());
		writeName(buff);
	}

	buff.writeInt(htonl(arr.size()));
	for (const long v : arr)
		buff.writeLong(v);
}

NbtTagType NbtTagLongArray::getType()
{
	return LONG_ARRAY;
}
