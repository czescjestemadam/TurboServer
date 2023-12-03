#include "command_manager.hh"

#include "../utils/str_utils.hh"

#include "server/stop_command.hh"
#include "server/tps_command.hh"
#include "server/mspt_command.hh"

void CommandManager::registerCommands()
{
	registerCommand(std::make_unique<StopCommand>());
	registerCommand(std::make_unique<TpsCommand>());
	registerCommand(std::make_unique<MsptCommand>());
}

void CommandManager::registerCommand(std::unique_ptr<Command>&& cmd)
{
	commands.push_back(std::move(cmd));
}

bool CommandManager::execute(CommandSender* sender, const std::string& str)
{
	if (str.empty())
		return false;

	std::vector<std::string> args = StrUtils::split(StrUtils::trimc(str));
	std::string alias = args.front();
	args.erase(args.begin());
	return execute(sender, alias, args);
}

bool CommandManager::execute(CommandSender* sender, const std::string& alias, const std::vector<std::string>& args)
{
	Command* command = getCommand(alias);
	return command && command->execute(sender, alias, args);
}

std::vector<std::string> CommandManager::suggest(CommandSender* sender, const std::string& str)
{
	if (str.empty())
		return {};

	std::vector<std::string> args = StrUtils::split(StrUtils::trimc(str));
	std::string alias = args.front();
	args.erase(args.begin());
	return suggest(sender, alias, args);
}

std::vector<std::string> CommandManager::suggest(CommandSender* sender, const std::string& alias, const std::vector<std::string>& args)
{
	Command* command = getCommand(alias);
	if (command)
		return command->suggest(sender, alias, args);
	return {};
}

Command* CommandManager::getCommand(const std::string& name)
{
	for (const std::unique_ptr<Command>& cmd : commands)
		if (cmd->getName() == name || cmd->matchAlias(name))
			return cmd.get();

	return nullptr;
}
