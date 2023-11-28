#include "entity_hover_event.hh"

EntityHoverEvent::EntityHoverEvent(Entity* entity) : entity(entity)
{
}

std::string EntityHoverEvent::getAction()
{
	return "show_entity";
}

nlohmann::json EntityHoverEvent::serializeContents()
{
	return {}; // todo
}
