#include "click_event_action.hh"

ClickEventAction::ClickEventAction(int id, std::string name) : id(id), name(std::move(name))
{
}

const std::string& ClickEventAction::getName() const
{
	return name;
}

bool ClickEventAction::operator==(const ClickEventAction& rhs) const
{
	return id == rhs.id;
}

bool ClickEventAction::operator!=(const ClickEventAction& rhs) const
{
	return !(rhs == *this);
}

ClickEventAction ClickEventAction::OPEN_URL = { 0, "open_url" };
ClickEventAction ClickEventAction::RUN_COMMAND = { 1, "run_command" };
ClickEventAction ClickEventAction::SUGGEST_COMMAND = { 2, "suggest_command" };
ClickEventAction ClickEventAction::CHANGE_PAGE = { 3, "change_page" };
ClickEventAction ClickEventAction::COPY_TO_CLIPBOARD = { 3, "copy_to_clipboard" };
