#include "nbt_tag_compound.hh"

NbtTagCompound::NbtTagCompound(const std::unordered_map<std::string, std::unique_ptr<NbtTag>>& tags)
{
	this->tags.reserve(tags.size());
	for (auto& [key, val] : tags)
		this->tags[key] = val->copy();
}

std::unique_ptr<NbtTag> NbtTagCompound::copy()
{
	return std::make_unique<NbtTagCompound>(tags);
}

void NbtTagCompound::write(PacketBuff& buff)
{
	for (auto& [ key, val ] : tags)
		writeTag(key, val, buff);

	buff.writeByte(0);
}

NbtTagType NbtTagCompound::getType()
{
	return COMPOUND;
}

int NbtTagCompound::getSizeBytes()
{
	int size = 48;

	for (auto& [ key, val ] : tags)
	{
		size += 28 + 2 * key.length();
		size += 36 + val->getSizeBytes();
	}

	return 48;
}

void NbtTagCompound::writeTag(const std::string& key, std::unique_ptr<NbtTag>& tag, PacketBuff& buff)
{
	buff.writeByte(tag->getType());
	if (tag->getType())
	{
		buff.writeBytes((byte_t*)key.c_str(), key.length());
		tag->write(buff);
	}
}
