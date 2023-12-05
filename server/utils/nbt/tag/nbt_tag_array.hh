#pragma once
#include "nbt_tag.hh"

#include <vector>

template<class T>
class NbtTagArray : public NbtTag
{
public:
	std::vector<T> arr;

	NbtTagArray() = default;
	explicit NbtTagArray(const std::vector<T>& arr) : arr(arr)
	{
	}
};

class NbtTagByteArray : public NbtTagArray<byte_t>
{
public:
	NbtTagByteArray() = default;
	explicit NbtTagByteArray(const std::vector<byte_t>& arr);

	std::unique_ptr<NbtTag> copy() override;
	void write(PacketBuff& buff) override;

	NbtTagType getType() override;
	int getSizeBytes() override;
};

class NbtTagIntArray : public NbtTagArray<int>
{
public:
	NbtTagIntArray() = default;
	explicit NbtTagIntArray(const std::vector<int>& arr);

	std::unique_ptr<NbtTag> copy() override;
	void write(PacketBuff& buff) override;

	NbtTagType getType() override;
	int getSizeBytes() override;
};

class NbtTagLongArray : public NbtTagArray<long>
{
public:
	NbtTagLongArray() = default;
	explicit NbtTagLongArray(const std::vector<long>& arr);

	std::unique_ptr<NbtTag> copy() override;
	void write(PacketBuff& buff) override;
	NbtTagType getType() override;
	int getSizeBytes() override;
};
