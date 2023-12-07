#include "nbt.hh"

#include "tag/nbt_tag_end.hh"
#include "tag/nbt_tag_primitive.hh"
#include "tag/nbt_tag_array.hh"
#include "tag/nbt_tag_list.hh"
#include "tag/nbt_tag_compound.hh"

NBT::TagPtr NBT::tagFromType(NbtTagType type)
{
	switch (type)
	{
		case END: return std::make_unique<NbtTagEnd>();
		case BYTE: return std::make_unique<NbtTagByte>(0);
		case SHORT: return std::make_unique<NbtTagShort>(0);
		case INT: return std::make_unique<NbtTagInt>(0);
		case LONG: return std::make_unique<NbtTagLong>(0);
		case FLOAT: return std::make_unique<NbtTagFloat>(0);
		case DOUBLE: return std::make_unique<NbtTagDouble>(0);
		case BYTE_ARRAY: return std::make_unique<NbtTagByteArray>();
		case STRING: return std::make_unique<NbtTagString>("");
		case LIST: return std::make_unique<NbtTagList>();
		case COMPOUND: return std::make_unique<NbtTagCompound>();
		case INT_ARRAY: return std::make_unique<NbtTagIntArray>();
		case LONG_ARRAY: return std::make_unique<NbtTagLongArray>();

		case UNKNOWN_TAG:
		default:
			return nullptr;
	}
}

NBT::TagPtr NBT::read(std::istream& is)
{


	return nullptr;
}
