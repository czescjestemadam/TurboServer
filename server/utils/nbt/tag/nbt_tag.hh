#pragma once
#include "nbt_tag_type.hh"
#include "server/network/packet_buff.hh"

#include <memory>

class NbtTag
{
public:
	virtual ~NbtTag() = default;

	virtual std::unique_ptr<NbtTag> copy() = 0;
	virtual void write(PacketBuff& buff) = 0;

	virtual NbtTagType getType() = 0;
	virtual int getSizeBytes() = 0;
};
