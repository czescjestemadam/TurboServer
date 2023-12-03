#pragma once
#include "command.hh"

#include <vector>
#include <memory>
#include <string>

class CommandManager
{
	std::vector<std::unique_ptr<Command>> commands;

public:
	void registerCommands();
	void registerCommand(std::unique_ptr<Command>&& cmd);

	bool execute(CommandSender* sender, const std::string& str);
	bool execute(CommandSender* sender, const std::string& alias, const std::vector<std::string>& args);

	std::vector<std::string> suggest(CommandSender* sender, const std::string& str);
	std::vector<std::string> suggest(CommandSender* sender, const std::string& alias, const std::vector<std::string>& args);

	Command* getCommand(const std::string& name);
};
