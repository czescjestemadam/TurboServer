#pragma once
#include "nbt_tag.hh"

#include <unordered_map>

class NbtTagCompound : public NbtTag
{
public:
	std::unordered_map<std::string, std::unique_ptr<NbtTag>> tags;

	NbtTagCompound() = default;
	explicit NbtTagCompound(const std::unordered_map<std::string, std::unique_ptr<NbtTag>>& tags);

	std::unique_ptr<NbtTag> copy() override;
	void write(PacketBuff& buff) override;

	NbtTagType getType() override;
	int getSizeBytes() override;

private:
	static void writeTag(const std::string& key, std::unique_ptr<NbtTag>& tag, PacketBuff& buff);
};
