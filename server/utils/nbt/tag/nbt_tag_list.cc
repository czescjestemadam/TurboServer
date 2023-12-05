#include "nbt_tag_list.hh"

NbtTagList::NbtTagList(const std::vector<std::unique_ptr<NbtTag>>& arr) : arr(arr)
{
}

std::unique_ptr<NbtTag> NbtTagList::copy()
{
	return std::make_unique<NbtTagList>(arr);
}

void NbtTagList::write(PacketBuff& buff)
{
	buff.writeByte(arr.empty() ? NbtTagType::END : arr[0]->getType());
	buff.writeInt(arr.size());

	for (std::unique_ptr<NbtTag>& tag : arr)
		tag->write(buff);
}

NbtTagType NbtTagList::getType()
{
	return LIST;
}

int NbtTagList::getSizeBytes()
{
	int size = 37 + 4 * arr.size();

	for (std::unique_ptr<NbtTag>& tag : arr)
		size += tag->getSizeBytes();

	return size;
}
