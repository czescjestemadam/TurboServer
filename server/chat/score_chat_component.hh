#pragma once
#include "chat_component.hh"
#include "server/utils/uuid.hh"

class ScoreChatComponent : public ChatComponent
{
	struct Score
	{
		UUID entityUuid;
		const char* username;
		std::string objective;
		std::string value;
	} score;

public:
	explicit ScoreChatComponent(const Score& score);

protected:
	nlohmann::json json() const override;
};
