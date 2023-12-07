#pragma once
#include "nbt_tag.hh"

class NbtTagEnd : public NbtTag
{
public:
	std::unique_ptr<NbtTag> copy() override;
	void read(PacketBuff& buff, bool name) override;
	void write(PacketBuff& buff, bool name) override;

	NbtTagType getType() override;
};
