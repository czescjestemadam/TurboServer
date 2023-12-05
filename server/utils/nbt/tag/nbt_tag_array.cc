#include "nbt_tag_array.hh"

NbtTagByteArray::NbtTagByteArray(const std::vector<byte_t>& arr) : NbtTagArray(arr)
{
}

std::unique_ptr<NbtTag> NbtTagByteArray::copy()
{
	return std::make_unique<NbtTagByteArray>(arr);
}

void NbtTagByteArray::write(PacketBuff& buff)
{
	buff.writeInt(arr.size());
	buff.writeBytes(arr.data(), arr.size());
}

NbtTagType NbtTagByteArray::getType()
{
	return BYTE_ARRAY;
}

int NbtTagByteArray::getSizeBytes()
{
	return 24 + arr.size();
}


NbtTagIntArray::NbtTagIntArray(const std::vector<int>& arr) : NbtTagArray(arr)
{
}

std::unique_ptr<NbtTag> NbtTagIntArray::copy()
{
	return std::make_unique<NbtTagIntArray>(arr);
}

void NbtTagIntArray::write(PacketBuff& buff)
{
	buff.writeInt(arr.size());
	for (int i : arr)
		buff.writeInt(i);
}

NbtTagType NbtTagIntArray::getType()
{
	return INT_ARRAY;
}

int NbtTagIntArray::getSizeBytes()
{
	return 24 + 4 * arr.size();
}


NbtTagLongArray::NbtTagLongArray(const std::vector<long>& arr) : NbtTagArray(arr)
{
}

std::unique_ptr<NbtTag> NbtTagLongArray::copy()
{
	return std::make_unique<NbtTagLongArray>(arr);
}

void NbtTagLongArray::write(PacketBuff& buff)
{
	buff.writeInt(arr.size());
	for (long l : arr)
		buff.writeLong(l);
}

NbtTagType NbtTagLongArray::getType()
{
	return LONG_ARRAY;
}

int NbtTagLongArray::getSizeBytes()
{
	return 24 + 8 * arr.size();
}
