#include "commands_config.hh"

#include "json_helper.hh"

void CommandsConfig::load(nlohmann::json&& j)
{
	JSON_HELPER_READ(log)

	JSON_HELPER_READ(kickForSpam)
	JSON_HELPER_READ(spamThreshold)
	JSON_HELPER_READ(spamExceptions)

	JSON_HELPER_READ(unknownCommandMessage)
}

nlohmann::json CommandsConfig::save()
{
	nlohmann::json j;

	JSON_HELPER_WRITE(log)

	JSON_HELPER_WRITE(kickForSpam)
	JSON_HELPER_WRITE(spamThreshold)
	JSON_HELPER_WRITE(spamExceptions)

	JSON_HELPER_WRITE(unknownCommandMessage)

	return j;
}

std::string CommandsConfig::getName()
{
	return "commands";
}
