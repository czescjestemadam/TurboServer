#include "permission_manager.hh"

void PermissionManager::init(PermissionsConfig* config)
{
	this->cfg = config;

	// todo register permissions
}

void PermissionManager::registerPermission(const Permission& perm)
{
	permissions.push_back(perm);
}

void PermissionManager::loadGroups()
{
	// todo init groups and perms
}

Permission* PermissionManager::getPermission(const std::string& name)
{
	for (Permission& perm : permissions)
		if (perm.name == name)
			return &perm;

	return nullptr;
}

Group* PermissionManager::getGroup(const std::string& name)
{
	for (Group& group : groups)
		if (group.name == name)
			return &group;

	return nullptr;
}
