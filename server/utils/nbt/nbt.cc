#include "nbt.hh"

#include "tag/nbt_tag_end.hh"
#include "tag/nbt_tag_primitive.hh"
#include "tag/nbt_tag_array.hh"
#include "tag/nbt_tag_list.hh"
#include "tag/nbt_tag_compound.hh"

std::unique_ptr<NbtTag> NBT::tagFromType(NbtTagType type)
{
	switch (type)
	{
		case END: return std::make_unique<NbtTagEnd>();
		case BYTE: return std::make_unique<NbtTagByte>("", 0);
		case SHORT: return std::make_unique<NbtTagShort>("", 0);
		case INT: return std::make_unique<NbtTagInt>("", 0);
		case LONG: return std::make_unique<NbtTagLong>("", 0);
		case FLOAT: return std::make_unique<NbtTagFloat>("", 0);
		case DOUBLE: return std::make_unique<NbtTagDouble>("", 0);
		case BYTE_ARRAY: return std::make_unique<NbtTagByteArray>();
		case STRING: return std::make_unique<NbtTagString>("", "");
		case LIST: return std::make_unique<NbtTagList>();
		case COMPOUND: return std::make_unique<NbtTagCompound>();
		case INT_ARRAY: return std::make_unique<NbtTagIntArray>();
		case LONG_ARRAY: return std::make_unique<NbtTagLongArray>();

		case UNKNOWN_TAG:
		default:
			return nullptr;
	}
}


std::unique_ptr<NbtTag> NBT::readStr(const std::string& str, std::unique_ptr<NbtTag>* parent)
{
	const PacketBuff buff((byte_t*)str.c_str(), str.length());
	return readCopy(buff, parent);
}

std::unique_ptr<NbtTag> NBT::read(PacketBuff& buff, std::unique_ptr<NbtTag>* parent)
{
	const NbtTagType type = static_cast<NbtTagType>(buff.readByte());

	std::unique_ptr<NbtTag> tag = tagFromType(type);
	tag->read(buff, true);

	return tag;
}

std::unique_ptr<NbtTag> NBT::readCopy(PacketBuff buff, std::unique_ptr<NbtTag>* parent)
{
	return read(buff, parent);
}


PacketBuff NBT::write(std::unique_ptr<NbtTag>& tag)
{
	PacketBuff buff;
	write(buff, tag);
	return buff;
}


void NBT::write(PacketBuff& buff, std::unique_ptr<NbtTag>& tag)
{
	tag->write(buff, true);
}
