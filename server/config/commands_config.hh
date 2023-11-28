#pragma once
#include "iconfig.hh"

class CommandsConfig : public IConfig
{
public:
	bool log = true;

	bool kickForSpam = false;
	// per second
	int spamThreshold = 6;
	std::vector<std::string> spamExceptions;

	std::string unknownCommandMessage = "Unknown command. Type '/help' for help.";


	void load(nlohmann::json&& j) override;
	nlohmann::json save() override;

	std::string getName() override;
};
