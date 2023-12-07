#include "nbt_tag.hh"

#include <netinet/in.h>

void NbtTag::readName(PacketBuff& buff)
{
	name = readStr(buff);
}

void NbtTag::writeName(PacketBuff& buff)
{
	writeStr(buff, name);
}


std::string NbtTag::readStr(PacketBuff& buff)
{
	ushort len = ntohs(buff.readShortU());

	if (!len)
		return "";

	char cstr[len + 1];
	buff.readBytes(reinterpret_cast<byte_t*>(cstr), len);
	cstr[len] = 0;

	return cstr;
}

void NbtTag::writeStr(PacketBuff& buff, const std::string& str)
{
	ushort len = str.length();
	buff.writeShortU(htons(len));
	if (len)
		buff.writeBytes((byte_t*)str.c_str(), len);
}
