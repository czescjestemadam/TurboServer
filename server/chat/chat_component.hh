#pragma once
#include "chat_format.hh"
#include "chat_font.hh"
#include "server/chat/event/click_event.hh"
#include "server/chat/event/hover_event.hh"

#include <memory>
#include <vector>

class ChatComponent
{
protected:
	bool bold;
	bool italic;
	bool underline;
	bool strikethrough;
	bool obfuscated;
	ChatFont* font;
	ChatFormat* color;
	std::string insertion; // text to insert in chat on click

	ClickEvent clickEvent;
	std::unique_ptr<HoverEvent> hoverEvent;

	std::vector<ChatComponent> extra;

public:

	virtual std::string toString() const;
};
