#pragma once
#include "hover_event.hh"
#include "server/entity/entity.hh"

class EntityHoverEvent : public HoverEvent
{
	Entity* entity;

public:
	explicit EntityHoverEvent(Entity* entity);

	std::string getAction() override;
	nlohmann::json serializeContents() override;
};
