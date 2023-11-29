#include "command_manager.hh"

#include "../utils/str_utils.hh"

bool CommandManager::execute(CommandSender* sender, const std::string& str)
{
	if (str.empty())
		return false;

	std::vector<std::string> args = StrUtils::split(StrUtils::trimc(str));
	std::string alias = args.at(0);
	return execute(sender, alias, args);
}

bool CommandManager::execute(CommandSender* sender, const std::string& alias, const std::vector<std::string>& args)
{
	Command* command = getCommand(alias);
	return command && command->execute(sender, alias, args);
}

Command* CommandManager::getCommand(const std::string& name)
{
	for (const std::unique_ptr<Command>& cmd : commands)
		if (cmd->getName() == name || cmd->matchAlias(name))
			cmd.get();

	return nullptr;
}
