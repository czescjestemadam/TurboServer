#include "nbt_tag_compound.hh"
#include "server/utils/nbt/nbt.hh"

NbtTagCompound::NbtTagCompound(const std::string& name, const std::map<std::string, std::unique_ptr<NbtTag>>& tags)
{
	this->name = name;

//	this->tags.reserve(tags.size()); // unordered_map
	for (auto& [key, val] : tags)
		this->tags[key] = val->copy();
}

std::unique_ptr<NbtTag> NbtTagCompound::copy()
{
	return std::make_unique<NbtTagCompound>(name, tags);
}

void NbtTagCompound::read(PacketBuff& buff, bool name)
{
	if (name)
		readName(buff);

	NbtTagType type;
	while ((type = (NbtTagType)buff.readByte()) != 0)
	{
		std::unique_ptr<NbtTag> tag = NBT::tagFromType(type);
		tag->read(buff, true);

		std::string& key = tag->name;
		tags[key] = std::move(tag);
	}
}

void NbtTagCompound::write(PacketBuff& buff, bool name)
{
	if (name)
	{
		buff.writeByte(getType());
		writeName(buff);
	}

	for (auto& [key, val] : tags)
		val->write(buff, true);

	buff.writeByte(END);
}

NbtTagType NbtTagCompound::getType()
{
	return COMPOUND;
}
