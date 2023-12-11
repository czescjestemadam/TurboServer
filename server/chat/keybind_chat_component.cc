#include "keybind_chat_component.hh"

KeybindChatComponent::KeybindChatComponent(const std::string& key) : key(key)
{
}

nlohmann::json KeybindChatComponent::json() const
{
	auto j = baseJson();
	j["keybind"] = key;

	return j;
}
