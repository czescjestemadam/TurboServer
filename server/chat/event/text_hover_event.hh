#pragma once
#include "hover_event.hh"

class TextHoverEvent : public HoverEvent
{
	std::string text; // todo change to TextChatComponent

public:
	explicit TextHoverEvent(std::string text);

	std::string getAction() override;
	nlohmann::json serializeContents() override;
};
