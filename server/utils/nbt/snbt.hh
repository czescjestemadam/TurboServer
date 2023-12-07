#pragma once
#include "tag/nbt_tag.hh"

namespace SNBT
{
	using TagPtr = std::unique_ptr<NbtTag>;

	TagPtr parse(const std::string& snbt);

	std::string print(TagPtr tag);
}
