#pragma once
#include "chat_component.hh"

class KeybindChatComponent : public ChatComponent
{
	std::string key;

public:
	explicit KeybindChatComponent(const std::string& key);

protected:
	nlohmann::json json() const override;
};
