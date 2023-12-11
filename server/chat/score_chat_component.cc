#include "score_chat_component.hh"

ScoreChatComponent::ScoreChatComponent(const ScoreChatComponent::Score& score) : score(score)
{
}

nlohmann::json ScoreChatComponent::json() const
{
	auto j = baseJson();
	j["asd"] = "123"; //todo

	return j;
}
