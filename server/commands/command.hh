#pragma once
#include "command_sender.hh"

#include <string>
#include <vector>

class Command
{
	std::string name;
	std::vector<std::string> aliases;

	std::string permission;
	std::string description;
	std::string usage;

public:
	Command(std::string name, std::string permission);
	Command(std::string name, const std::vector<std::string>& aliases, std::string permission, std::string description, std::string usage);
	virtual ~Command() = default;

	virtual bool execute(CommandSender* sender, std::string alias, std::vector<std::string> args) = 0;

	bool matchAlias(const std::string& alias);

	const std::string& getName() const;
	const std::vector<std::string>& getAliases() const;
	const std::string& getPermission() const;
	const std::string& getDescription() const;
	const std::string& getUsage() const;
};
