#pragma once
#include "nbt_tag.hh"

#include <vector>

class NbtTagList : public NbtTag
{
public:
	std::vector<std::unique_ptr<NbtTag>> arr;

	NbtTagList() = default;
	explicit NbtTagList(const std::vector<std::unique_ptr<NbtTag>>& arr);

	std::unique_ptr<NbtTag> copy() override;
	void write(PacketBuff& buff) override;

	NbtTagType getType() override;
	int getSizeBytes() override;
};
