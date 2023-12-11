#include "item_hover_event.hh"

ItemHoverEvent::ItemHoverEvent(const ItemStack& item) : item(item)
{
}

std::string ItemHoverEvent::getAction()
{
	return "show_item";
}

std::string ItemHoverEvent::getContents()
{
	return "";
}
