#pragma once
#include "click_event_action.hh"

#include <string>

class ClickEvent
{
	ClickEventAction* action = nullptr;
	std::string value;

public:
	ClickEvent() = default;
	ClickEvent(ClickEventAction* action, std::string value);

	ClickEventAction* getAction() const;
	const std::string& getValue() const;
};
