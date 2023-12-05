#pragma once
#include "nbt_tag.hh"

template<class T>
class NbtTagPrimitive : public NbtTag
{
public:
	T val;

	explicit NbtTagPrimitive(T val) : val(val)
	{
	}
};

class NbtTagByte : public NbtTagPrimitive<byte_t>
{
public:
	explicit NbtTagByte(byte_t val);

	std::unique_ptr<NbtTag> copy() override;
	void write(PacketBuff& buff) override;

	NbtTagType getType() override;
	int getSizeBytes() override;
};

class NbtTagShort : public NbtTagPrimitive<short>
{
public:
	explicit NbtTagShort(short val);

	std::unique_ptr<NbtTag> copy() override;
	void write(PacketBuff& buff) override;

	NbtTagType getType() override;
	int getSizeBytes() override;
};

class NbtTagInt : public NbtTagPrimitive<int>
{
public:
	explicit NbtTagInt(int val);

	std::unique_ptr<NbtTag> copy() override;
	void write(PacketBuff& buff) override;

	NbtTagType getType() override;
	int getSizeBytes() override;
};

class NbtTagLong : public NbtTagPrimitive<long>
{
public:
	explicit NbtTagLong(long val);

	std::unique_ptr<NbtTag> copy() override;
	void write(PacketBuff& buff) override;

	NbtTagType getType() override;
	int getSizeBytes() override;
};

class NbtTagFloat : public NbtTagPrimitive<float>
{
public:
	explicit NbtTagFloat(float val);

	std::unique_ptr<NbtTag> copy() override;
	void write(PacketBuff& buff) override;

	NbtTagType getType() override;
	int getSizeBytes() override;
};

class NbtTagDouble : public NbtTagPrimitive<double>
{
public:
	explicit NbtTagDouble(double val);

	std::unique_ptr<NbtTag> copy() override;
	void write(PacketBuff& buff) override;
	NbtTagType getType() override;
	int getSizeBytes() override;
};

class NbtTagString : public NbtTagPrimitive<std::string>
{
public:
	explicit NbtTagString(const std::string& val);

	std::unique_ptr<NbtTag> copy() override;
	void write(PacketBuff& buff) override;

	NbtTagType getType() override;
	int getSizeBytes() override;
};
