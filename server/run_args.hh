#pragma once
#include <vector>
#include <string>
#include <unordered_map>
#include <optional>

class RunArgs
{
	std::vector<std::string> argsStr;

	std::vector<std::string> flags;
	std::unordered_map<std::string, std::string> args;

public:
	RunArgs(int argc, char *argv[]);

	void parse();

	bool hasFlag(const std::string& name) const;
	std::optional<std::string> getArg(const std::string& name) const;

	std::string toString() const;
};
