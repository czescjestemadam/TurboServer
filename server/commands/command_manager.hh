#pragma once
#include "command.hh"

#include <vector>
#include <memory>
#include <string>

class CommandManager
{
	std::vector<std::unique_ptr<Command>> commands;

public:
	void registerCommand();

	bool execute(CommandSender* sender, const std::string& str);
	bool execute(CommandSender* sender, const std::string& alias, const std::vector<std::string>& args);

	Command* getCommand(const std::string& name);
};
