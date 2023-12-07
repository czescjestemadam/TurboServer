#pragma once
#include "tag/nbt_tag.hh"

#include <string>

namespace NBT
{
	std::unique_ptr<NbtTag> tagFromType(NbtTagType type);


	std::unique_ptr<NbtTag> readStr(const std::string& str, std::unique_ptr<NbtTag>* parent = nullptr);
	std::unique_ptr<NbtTag> read(PacketBuff & buff, std::unique_ptr<NbtTag> * parent = nullptr);
	std::unique_ptr<NbtTag> readCopy(PacketBuff buff, std::unique_ptr<NbtTag>* parent = nullptr);

	PacketBuff write(std::unique_ptr<NbtTag>& tag);
	void write(PacketBuff& buff, std::unique_ptr<NbtTag>& tag);
}
