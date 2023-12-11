#include "text_chat_component.hh"

TextChatComponent::TextChatComponent(const std::string& text) : text(text)
{
}

nlohmann::json TextChatComponent::json() const
{
	auto j = baseJson();
	j["text"] = text;

	return j;
}
