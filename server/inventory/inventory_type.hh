#pragma once
#include <string>

class Inventory;

class InventoryType
{
	int id;

public:
	std::string name;
	int size;

	InventoryType(int id, const std::string& name, int size);


	static InventoryType PLAYER;
	static InventoryType CHEST;
	static InventoryType DOUBLE_CHEST;
	static InventoryType ENDER_CHEST;
	static InventoryType BOAT_CHEST;
	static InventoryType MINECART_CHEST;
	static InventoryType SHULKER;
	static InventoryType CRAFTING;
	static InventoryType FURNACE;
	static InventoryType HOPPER;
	static InventoryType DISPENSER;
	static InventoryType DROPPER;
	static InventoryType BREWING_STAND;
};
