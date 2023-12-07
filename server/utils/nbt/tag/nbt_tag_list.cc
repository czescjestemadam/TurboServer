#include "nbt_tag_list.hh"
#include "server/utils/nbt/nbt.hh"

#include <netinet/in.h>

NbtTagList::NbtTagList(const std::string& name, const std::vector<std::unique_ptr<NbtTag>>& arr)
{
	this->name = name;

	this->arr.reserve(arr.size());
	for (const std::unique_ptr<NbtTag>& tag : arr)
		this->arr.push_back(tag->copy());
}

std::unique_ptr<NbtTag> NbtTagList::copy()
{
	return std::make_unique<NbtTagList>(name, arr);
}

void NbtTagList::read(PacketBuff& buff, bool name)
{
	if (name)
		readName(buff);

	NbtTagType type = (NbtTagType)buff.readByte();
	int len = ntohl(buff.readInt());

	for (int i = 0; i < len; ++i)
	{
		std::unique_ptr<NbtTag> tag = NBT::tagFromType(type);
		tag->read(buff, false);
		arr.push_back(std::move(tag));
	}
}

void NbtTagList::write(PacketBuff& buff, bool name)
{
	if (name)
	{
		buff.writeByte(getType());
		writeName(buff);
	}

	buff.writeByte(arr.empty() ? END : arr[0]->getType());
	buff.writeInt(htonl(arr.size()));

	for (std::unique_ptr<NbtTag>& tag : arr)
		tag->write(buff, false);
}

NbtTagType NbtTagList::getType()
{
	return LIST;
}

