#include "inventory_type.hh"

#include "inventory.hh"

InventoryType::InventoryType(int id, const std::string& name, int size) : id(id), name(name), size(size)
{
}

InventoryType InventoryType::PLAYER = { 0, "PLAYER", 41 };
InventoryType InventoryType::CHEST = { 1, "CHEST", 27 };
InventoryType InventoryType::DOUBLE_CHEST = { 2, "DOUBLE_CHEST", 54 };
InventoryType InventoryType::ENDER_CHEST = { 3, "ENDER_CHEST", 27 };
InventoryType InventoryType::BOAT_CHEST = { 4, "BOAT_CHEST", 27 };
InventoryType InventoryType::MINECART_CHEST = { 5, "MINECART_CHEST", 27 };
InventoryType InventoryType::SHULKER = { 6, "SHULKER", 27 };
InventoryType InventoryType::CRAFTING = { 7, "CRAFTING", 10 };
InventoryType InventoryType::FURNACE = { 8, "FURNACE", 3 };
InventoryType InventoryType::HOPPER = { 9, "HOPPER", 5 };
InventoryType InventoryType::DISPENSER = { 10, "DISPENSER", 9 };
InventoryType InventoryType::DROPPER = { 11, "DROPPER", 9 };
InventoryType InventoryType::BREWING_STAND = { 12, "BREWING_STAND", 5 };
