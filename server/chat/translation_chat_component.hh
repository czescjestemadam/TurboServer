#pragma once
#include "chat_component.hh"

class TranslationChatComponent : public ChatComponent
{
	std::string translate;

public:
	explicit TranslationChatComponent(const std::string& translate);

protected:
	nlohmann::json json() const override;
};
