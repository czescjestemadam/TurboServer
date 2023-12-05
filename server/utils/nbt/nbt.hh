#pragma once
#include "tag/nbt_tag.hh"

#include <string>

namespace NBT
{
	using TagPtr = std::unique_ptr<NbtTag>;

	TagPtr tagFromType(NbtTagType type);


	TagPtr read(std::istream& is);

	std::string write(TagPtr tag);
	std::ostream& operator<<(std::ostream& os, TagPtr tag);
}
