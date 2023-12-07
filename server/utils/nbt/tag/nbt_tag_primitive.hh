#pragma once
#include "nbt_tag.hh"

template<class T>
class NbtTagPrimitive : public NbtTag
{
public:
	T val;

	explicit NbtTagPrimitive(const std::string& name, T val) : val(val)
	{
		this->name = name;
	}
};

class NbtTagByte : public NbtTagPrimitive<byte_t>
{
public:
	explicit NbtTagByte(const std::string& name, byte_t val);

	std::unique_ptr<NbtTag> copy() override;
	void read(PacketBuff& buff, bool name) override;
	void write(PacketBuff& buff, bool name) override;

	NbtTagType getType() override;
};

class NbtTagShort : public NbtTagPrimitive<short>
{
public:
	explicit NbtTagShort(const std::string& name, short val);

	std::unique_ptr<NbtTag> copy() override;
	void read(PacketBuff& buff, bool name) override;
	void write(PacketBuff& buff, bool name) override;

	NbtTagType getType() override;
};

class NbtTagInt : public NbtTagPrimitive<int>
{
public:
	explicit NbtTagInt(const std::string& name, int val);

	std::unique_ptr<NbtTag> copy() override;
	void read(PacketBuff& buff, bool name) override;
	void write(PacketBuff& buff, bool name) override;

	NbtTagType getType() override;
};

class NbtTagLong : public NbtTagPrimitive<long>
{
public:
	explicit NbtTagLong(const std::string& name, long val);

	std::unique_ptr<NbtTag> copy() override;
	void read(PacketBuff& buff, bool name) override;
	void write(PacketBuff& buff, bool name) override;

	NbtTagType getType() override;
};

class NbtTagFloat : public NbtTagPrimitive<float>
{
public:
	explicit NbtTagFloat(const std::string& name, float val);

	std::unique_ptr<NbtTag> copy() override;
	void read(PacketBuff& buff, bool name) override;
	void write(PacketBuff& buff, bool name) override;

	NbtTagType getType() override;
};

class NbtTagDouble : public NbtTagPrimitive<double>
{
public:
	explicit NbtTagDouble(const std::string& name, double val);

	std::unique_ptr<NbtTag> copy() override;
	void read(PacketBuff& buff, bool name) override;
	void write(PacketBuff& buff, bool name) override;

	NbtTagType getType() override;
};

class NbtTagString : public NbtTagPrimitive<std::string>
{
public:
	explicit NbtTagString(const std::string& name, const std::string& val);

	std::unique_ptr<NbtTag> copy() override;
	void read(PacketBuff& buff, bool name) override;
	void write(PacketBuff& buff, bool name) override;

	NbtTagType getType() override;
};
