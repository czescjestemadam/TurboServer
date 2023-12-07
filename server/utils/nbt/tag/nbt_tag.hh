#pragma once
#include "nbt_tag_type.hh"
#include "server/network/packet_buff.hh"

#include <memory>

class NbtTag
{
public:
	std::string name;

	virtual ~NbtTag() = default;

	virtual std::unique_ptr<NbtTag> copy() = 0;
	virtual void read(PacketBuff& buff, bool name) = 0;
	virtual void write(PacketBuff& buff, bool name) = 0;

	virtual NbtTagType getType() = 0;


protected:
	void readName(PacketBuff& buff);
	void writeName(PacketBuff& buff);

	std::string readStr(PacketBuff& buff);
	void writeStr(PacketBuff& buff, const std::string& str);
};
