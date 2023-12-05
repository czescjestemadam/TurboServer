#include "snbt.hh"

#include "nbt.hh"

SNBT::TagPtr SNBT::parse(const std::string& snbt)
{
	return NBT::tagFromType(END);
}

std::string SNBT::print(SNBT::TagPtr tag)
{
	return "";
}
