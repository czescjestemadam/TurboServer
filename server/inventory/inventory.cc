#include "inventory.hh"

Inventory::Inventory(int size, InventoryType* type, const std::string& title) : size(size), type(type), title(title)
{
}

std::vector<Item>& Inventory::getContent()
{
	return content;
}
