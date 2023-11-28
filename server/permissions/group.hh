#pragma once
#include "permission.hh"

#include <string>
#include <vector>

class Group
{
public:
	std::string name;
	std::string prefix;
	std::string suffix;
	std::vector<AppliedPermission*> permissions;


	explicit Group(std::string name);
	Group(std::string name, std::string prefix, std::string suffix, const std::vector<AppliedPermission*>& permissions);

	bool hasPermission(const std::string& permName);
	bool getPermission(const std::string& permName);
};
