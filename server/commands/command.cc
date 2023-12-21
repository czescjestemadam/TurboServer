#include "command.hh"

#include <algorithm>
#include <utility>

Command::Command(std::string name, std::string permission) : name(std::move(name)), permission(std::move(permission))
{
}

Command::Command(std::string name, const std::vector<std::string>& aliases, std::string permission, std::string description, std::string usage)
		: name(std::move(name)), aliases(aliases), permission(std::move(permission)), description(std::move(description)), usage(std::move(usage))
{
}


bool Command::matchAlias(const std::string& alias)
{
	return std::ranges::find(aliases, alias) != aliases.end();
}


const std::string& Command::getName() const
{
	return name;
}

const std::vector<std::string>& Command::getAliases() const
{
	return aliases;
}

const std::string& Command::getPermission() const
{
	return permission;
}

const std::string& Command::getDescription() const
{
	return description;
}

const std::string& Command::getUsage() const
{
	return usage;
}
