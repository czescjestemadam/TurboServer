#pragma once
#include "../command.hh"

class VersionCommand : public Command
{
public:
	VersionCommand();

	bool execute(CommandSender* sender, const std::string& alias, const std::vector<std::string>& args) override;
	std::vector<std::string> suggest(CommandSender* sender, const std::string& alias, const std::vector<std::string>& args) override;
};
