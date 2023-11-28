#include "item_rarity.hh"

ItemRarity::ItemRarity(int id, ChatFormat* format) : id(id), format(format)
{
}

ChatFormat* ItemRarity::getFormat() const
{
	return format;
}

bool ItemRarity::operator==(const ItemRarity& rhs) const
{
	return id == rhs.id;
}

bool ItemRarity::operator!=(const ItemRarity& rhs) const
{
	return !(rhs == *this);
}

ItemRarity ItemRarity::COMMON = { 0, &ChatFormat::WHITE };
ItemRarity ItemRarity::UNCOMMON = { 1, &ChatFormat::YELLOW };
ItemRarity ItemRarity::RARE = { 2, &ChatFormat::AQUA };
ItemRarity ItemRarity::EPIC = { 3, &ChatFormat::LIGHT_PURPLE };
