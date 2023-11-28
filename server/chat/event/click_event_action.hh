#pragma once
#include <string>

class ClickEventAction
{
	int id;
	std::string name;

public:
	ClickEventAction(int id, std::string name);

	const std::string& getName() const;

	bool operator==(const ClickEventAction& rhs) const;
	bool operator!=(const ClickEventAction& rhs) const;

	static ClickEventAction OPEN_URL;
	static ClickEventAction RUN_COMMAND;
	static ClickEventAction SUGGEST_COMMAND;
	static ClickEventAction CHANGE_PAGE;
	static ClickEventAction COPY_TO_CLIPBOARD;
};
