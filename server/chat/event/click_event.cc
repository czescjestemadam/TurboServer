#include "click_event.hh"

ClickEvent::ClickEvent(ClickEventAction* action, std::string value) : action(action), value(std::move(value))
{
}

ClickEventAction* ClickEvent::getAction() const
{
	return action;
}

const std::string& ClickEvent::getValue() const
{
	return value;
}
