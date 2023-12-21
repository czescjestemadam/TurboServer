#include <utility>

#include "group.hh"

Group::Group(std::string name) : name(std::move(name))
{
}

Group::Group(std::string name, std::string prefix, std::string suffix, const std::vector<AppliedPermission*>& permissions) :
		name(std::move(name)), prefix(std::move(prefix)), suffix(std::move(suffix)), permissions(permissions)
{
}

bool Group::hasPermission(const std::string& permName)
{
	for (const AppliedPermission* perm : permissions)
		if (perm->name == permName)
			return true;

	return false;
}

bool Group::getPermission(const std::string& permName)
{
	for (const AppliedPermission* perm : permissions)
		if (perm->name == permName)
			return perm->value;

	return false;
}
