#pragma once
#include "hover_event.hh"

class TextHoverEvent : public HoverEvent
{
	std::string text;

public:
	explicit TextHoverEvent(std::string text);

	std::string getAction() override;
	std::string getContents() override;
};
