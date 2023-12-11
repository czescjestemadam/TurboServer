#pragma once
#include "hover_event.hh"
#include "server/item/item_stack.hh"

class ItemHoverEvent : public HoverEvent
{
	ItemStack item;

public:
	explicit ItemHoverEvent(const ItemStack& item);

	std::string getAction() override;
	std::string getContents() override;
};
