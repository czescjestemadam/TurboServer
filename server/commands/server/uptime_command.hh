#pragma once
#include "../command.hh"

class UptimeCommand : public Command
{
public:
	UptimeCommand();

	bool execute(CommandSender* sender, const std::string& alias, const std::vector<std::string>& args) override;
	std::vector<std::string> suggest(CommandSender* sender, const std::string& alias, const std::vector<std::string>& args) override;
};
