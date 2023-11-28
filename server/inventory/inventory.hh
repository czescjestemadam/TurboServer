#pragma once
#include "inventory_type.hh"
#include "../item/item.hh"

#include <vector>

class Inventory
{
	int size;
	InventoryType type;
	std::string title;
	std::vector<Item> content;

public:
	Inventory(int size, const InventoryType& type, const std::string& title);

	std::vector<Item>& getContent();
};
