#include "translation_chat_component.hh"

TranslationChatComponent::TranslationChatComponent(const std::string& translate) : translate(translate)
{
}

nlohmann::json TranslationChatComponent::json() const
{
	auto j = baseJson();
	j["translate"] = translate;

	return j;
}
