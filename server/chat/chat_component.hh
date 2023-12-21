#pragma once
#include "chat_format.hh"
#include "chat_font.hh"
#include "server/chat/event/click_event.hh"
#include "server/chat/event/hover_event.hh"

#include <memory>
#include <vector>

class ChatComponent
{
public:
	bool bold = false;
	bool italic = false;
	bool underline = false;
	bool strikethrough = false;
	bool obfuscated = false;
	ChatFont* font = nullptr;
	ChatFormat* color = nullptr;
	std::string insertion; // text to insert in chat on click

	ClickEvent clickEvent;
	std::unique_ptr<HoverEvent> hoverEvent;

	std::vector<std::unique_ptr<ChatComponent>> extra;


	virtual ~ChatComponent() = default;

	std::string toString() const;

protected:
	virtual nlohmann::json json() const = 0;
	nlohmann::json baseJson() const;
};
