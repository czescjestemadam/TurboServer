#pragma once
#include "nbt_tag.hh"

#include <vector>

class NbtTagList : public NbtTag
{
public:
	std::vector<std::unique_ptr<NbtTag>> arr;

	NbtTagList() = default;
	explicit NbtTagList(const std::string& name, const std::vector<std::unique_ptr<NbtTag>>& arr);

	std::unique_ptr<NbtTag> copy() override;
	void read(PacketBuff& buff, bool name) override;
	void write(PacketBuff& buff, bool name) override;

	NbtTagType getType() override;
};
