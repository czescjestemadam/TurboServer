#pragma once
#include "../command.hh"

class TpsCommand : public Command
{
public:
	TpsCommand();

	bool execute(CommandSender* sender, const std::string& alias, const std::vector<std::string>& args) override;
	std::vector<std::string> suggest(CommandSender* sender, const std::string& alias, const std::vector<std::string>& args) override;
};
