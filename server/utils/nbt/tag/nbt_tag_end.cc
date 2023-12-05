#include "nbt_tag_end.hh"

std::unique_ptr<NbtTag> NbtTagEnd::copy()
{
	return std::make_unique<NbtTagEnd>();
}

void NbtTagEnd::write(PacketBuff& buff)
{
}

NbtTagType NbtTagEnd::getType()
{
	return END;
}

int NbtTagEnd::getSizeBytes()
{
	return 8;
}
