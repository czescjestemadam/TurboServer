#include "entity_hover_event.hh"

#include <format>

EntityHoverEvent::EntityHoverEvent(Entity* entity) : entity(entity)
{
}

std::string EntityHoverEvent::getAction()
{
	return "show_entity";
}

std::string EntityHoverEvent::getContents()
{
	return std::format("{{id:{},name:{}}}", entity->uuid.toString(), entity->getName());
}
