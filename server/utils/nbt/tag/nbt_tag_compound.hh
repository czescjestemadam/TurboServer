#pragma once
#include "nbt_tag.hh"

#include <map>

class NbtTagCompound : public NbtTag
{
public:
	std::map<std::string, std::unique_ptr<NbtTag>> tags;

	NbtTagCompound() = default;
	explicit NbtTagCompound(const std::string& name, const std::map<std::string, std::unique_ptr<NbtTag>>& tags);

	std::unique_ptr<NbtTag> copy() override;
	void read(PacketBuff& buff, bool name) override;
	void write(PacketBuff& buff, bool name) override;

	NbtTagType getType() override;
};
