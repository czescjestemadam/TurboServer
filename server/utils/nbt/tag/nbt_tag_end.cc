#include "nbt_tag_end.hh"

std::unique_ptr<NbtTag> NbtTagEnd::copy()
{
	return std::make_unique<NbtTagEnd>();
}

void NbtTagEnd::read(PacketBuff& buff, bool name)
{
}

void NbtTagEnd::write(PacketBuff& buff, bool name)
{
	buff.writeByte(getType());
}

NbtTagType NbtTagEnd::getType()
{
	return END;
}

