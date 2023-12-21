#pragma once
#include "group.hh"
#include "server/config/permissions_config.hh"

#include <vector>

class PermissionManager
{
	PermissionsConfig* cfg;

	std::vector<Permission> permissions;
	std::vector<Group> groups;

public:
	void init(PermissionsConfig* config);

	void registerPermission(const Permission& perm);

	void loadGroups();

	Permission* getPermission(const std::string& name);
	Group* getGroup(const std::string& name);
};
