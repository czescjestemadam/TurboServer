#pragma once
#include "chat_component.hh"

class TextChatComponent : public ChatComponent
{
	std::string text;

public:
	explicit TextChatComponent(const std::string& text);

protected:
	nlohmann::json json() const override;
};
