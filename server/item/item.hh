#pragma once
#include "item_rarity.hh"

class Item
{
	ItemRarity* rarity;
	int maxStackSize;
	int maxDamage;
	bool fireResistant;
	std::string descriptionId;

};
