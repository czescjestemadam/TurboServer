#pragma once
#include "server/chat/chat_format.hh"

class ItemRarity
{
	int id;
	ChatFormat* format;

public:
	ItemRarity(int id, ChatFormat* format);

	ChatFormat* getFormat() const;

	bool operator==(const ItemRarity& rhs) const;
	bool operator!=(const ItemRarity& rhs) const;

	static ItemRarity COMMON;
	static ItemRarity UNCOMMON;
	static ItemRarity RARE;
	static ItemRarity EPIC;
};
