#pragma once
#include "nbt_tag.hh"

class NbtTagEnd : public NbtTag
{
public:
	std::unique_ptr<NbtTag> copy() override;
	void write(PacketBuff& buff) override;

	NbtTagType getType() override;
	int getSizeBytes() override;
};
